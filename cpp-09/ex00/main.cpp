/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:36:50 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 18:36:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>

#include "BitcoinExchange.hpp"

std::map<std::time_t, int> parseInput(std::string filename) {
    std::ifstream infile;

    infile.open(static_cast<std::string>(filename));
    if (!infile.is_open()) {
        std::string errorMsg =
            "Error opening file '" + filename + "': " + std::strerror(errno);
        throw std::runtime_error(errorMsg);
    }

    std::map<std::time_t, int> data;

    return data;
}

#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>

void printExchangeRates(const BitcoinExchange::ExchangeRateMap& rates) {
    std::cout << "┌─────────────────────┬────────────┐" << std::endl;
    std::cout << "│ Date                │ Rate       │" << std::endl;
    std::cout << "├─────────────────────┼────────────┤" << std::endl;

    ExchangeRateMap::const_iterator it;
    for (it = rates.begin(); it != rates.end(); ++it) {
        std::time_t timestamp = it->first;
        double      rate = it->second;

        // Convert timestamp to tm struct (C++98 compatible)
        std::tm* timeinfo = std::localtime(&timestamp);

        if (timeinfo != NULL) {
            std::cout << "│ " << std::setfill('0') << std::setw(4)
                      << timeinfo->tm_year + 1900 << "-" << std::setw(2)
                      << timeinfo->tm_mon + 1 << "-" << std::setw(2)
                      << timeinfo->tm_mday << "        │ " << std::fixed
                      << std::setprecision(6) << std::setw(10) << rate << " │"
                      << std::endl;
        }
    }

    std::cout << "└─────────────────────┴────────────┘" << std::endl;
}

int main(int argc, char** argv) {
    // if (argc != 2) {
    //     std::cout << "Usage: ./btc input-data\n";
    //     return 0;
    // }

    BitcoinExchange btc;

    if (!btc.loadDatabase("data.csv")) {
        return 1;
    }

    BitcoinExchange::ExchangeRateMap rates = btc.getExchangeRates();
    printExchangeRates(rates);
    // ExchangeRateMap::const_iterator it;
    // for (it = rates.begin(); it != rates.end(); ++it) {
    // }
    (void)argv;
    (void)argc;

    return 0;
}
