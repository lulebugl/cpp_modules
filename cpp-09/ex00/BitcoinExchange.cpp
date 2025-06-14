/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:36:41 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 18:36:41 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadWallet(const std::string& filename) {
    std::ifstream infile(filename.c_str());

    if (!infile) {
        std::cerr << "Error opening file '" << filename
                  << "': " << std::strerror(errno) << "\n";
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty()) {
            continue;
        }

        size_t sep_pos = line.find(" | ");
        if (sep_pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        time_t timestamp = 0;
        double amount = 0;

        try {
            timestamp = parseDate(line.substr(0, sep_pos)).convertToEpoch();

            std::istringstream iss(line.substr(sep_pos + 3));
            if (!(iss >> amount)) {
                std::cerr << "Error: bad input => " << line << "\n";
                continue;
            }

        } catch (std::exception& e) {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        if (amount < 0) {
            std::cerr << "Error: not a positive number.\n";
            continue;
        }

        if (amount > 1000) {
            std::cerr << "Error: too large a number.\n";
            continue;
        }

        std::cout << timestampToString(timestamp) << " => " << amount << " = "
                  << getExchangeRate(timestamp) * amount << "\n";
    }

    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream infile(filename.c_str());

    if (!infile) {
        std::cerr << "Error loading database '" << filename
                  << "': " << std::strerror(errno) << "\n";
        return false;
    }

    std::string line;
    while (std::getline(infile, line)) {
        if (line == "date,exchange_rate" || line.empty()) {
            continue;
        }
        try {
            processLine(line);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << " in line: " << line << "\n";
            continue;
        }
    }

    return true;
}

void BitcoinExchange::processLine(const std::string& line) {
    size_t commaPos = line.find_first_of(",");
    if (commaPos == std::string::npos) {
        std::cerr << "Error: Invalid format - missing comma : " << line << "\n";
        return;
    }

    time_t timestamp = 0;
    double rate = 0;

    try {
        timestamp = parseDate(line.substr(0, commaPos)).convertToEpoch();
        std::istringstream iss(line.substr(commaPos + 1));
        if (!(iss >> rate)) {
            throw std::runtime_error("Invalid rate format");
        }

        if (rate < 0) {
            throw std::runtime_error("Error: negative rate value not allowed");
        }
    } catch (std::exception& e) {
        throw std::runtime_error("Error: proccesing line");
    }

    _exchangeRates[timestamp] = rate;
}

BitcoinExchange::Date BitcoinExchange::parseDate(const std::string& str) {
    BitcoinExchange::Date date(0, 0, 0);

    std::stringstream iss(str);
    char              dash1;
    char              dash2;

    if (!(iss >> date.year >> dash1 >> date.month >> dash2 >> date.day) ||
        dash1 != '-' || dash2 != '-') {
        throw std::invalid_argument("Invalid date format: " + str);
    }

    if (!date.isValid())
        throw std::invalid_argument("Invalid date values: " + str);

    return date;
}

BitcoinExchange::ExchangeRateMap BitcoinExchange::getExchangeRates() const {
    return _exchangeRates;
}

double BitcoinExchange::getExchangeRate(time_t timestamp) const {
    if (_exchangeRates.empty()) {
        return 0;
    }

    ExchangeRateMap::const_iterator rate =
        _exchangeRates.lower_bound(timestamp);

    if ((rate != _exchangeRates.begin() && rate->first > timestamp) ||
        rate == _exchangeRates.end()) {
        --rate;
    }
    return rate->second;
}

std::string BitcoinExchange::timestampToString(time_t timestamp) {
    std::ostringstream ss;
    struct tm          timeinfo;

    localtime_r(&timestamp, &timeinfo);

    ss << std::setfill('0') << std::setw(4) << timeinfo.tm_year + 1900 << '-'
       << std::setw(2) << timeinfo.tm_mon + 1 << '-' << std::setw(2)
       << timeinfo.tm_mday;

    return ss.str();
}

const int BitcoinExchange::Date::kDaysPerMonth[] = {0,  31, 28, 31, 30, 31, 30,
                                                    31, 31, 30, 31, 30, 31};

bool BitcoinExchange::Date::isValid() const {
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    int maxDays = kDaysPerMonth[month];
    if (month == 2 &&
        ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxDays = 29;
    }

    return day <= maxDays;
}

std::string BitcoinExchange::Date::convertToString() const {
    std::ostringstream ss;

    ss << std::setfill('0') << std::setw(4) << year << '-' << std::setw(2)
       << month << '-' << std::setw(2) << day;

    return ss.str();
}

time_t BitcoinExchange::Date::convertToEpoch() const {
    tm timeinfo;

    if (!isValid())
        return 0;

    timeinfo.tm_sec = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_hour = 12;
    timeinfo.tm_mday = day;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_isdst = -1;

    return mktime(&timeinfo);
}
