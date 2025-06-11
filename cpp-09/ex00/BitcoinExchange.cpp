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

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream infile(filename.c_str());

    if (!infile) {
        std::cerr << "Error loading database '" << filename
                  << "': " << strerror(errno) << "\n";
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

void BitcoinExchange::processLine(const std::string& line) throw() {
    size_t commaPos = line.find_first_of(",");
    if (commaPos == std::string::npos) {
        std::cerr << "Error: Invalid format - missing comma : " << line << "\n";
        return;
    }

    Date   date = parseDate(line.substr(0, commaPos));
    double rate = std::stod(line.substr(commaPos + 1));

    if (rate < 0) {
        std::cerr << "Error: negative rate value not allowed: " << line << "\n";
        return;
    }

    _exchangeRates[date.convertToEpoch()] = rate;
}

BitcoinExchange::ExchangeRateMap BitcoinExchange::getExchangeRates() const {
    return _exchangeRates;
}
const int BitcoinExchange::Date::kDaysPerMonth[] = {0,  31, 28, 31, 30, 31, 30,
                                                    31, 31, 30, 31, 30, 31};

bool BitcoinExchange::Date::isValid() {
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


BitcoinExchange::Date parseDate(const std::string& str) {
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

std::string BitcoinExchange::Date::convertToString() const {
    std::ostringstream ss;

    ss << std::setfill('0') << std::setw(4) << year << '-' << std::setw(2)
       << month << '-' << std::setw(2) << day;

    return ss.str();
}

std::time_t BitcoinExchange::Date::convertToEpoch() const {
    std::tm timeinfo;

    timeinfo.tm_sec = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_hour = 12;
    timeinfo.tm_mday = day;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_isdst = -1;

    return std::mktime(&timeinfo);
}