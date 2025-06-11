/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:36:41 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 18:36:41 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
   public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    struct Date {
        int year;
        int month;
        int day;

        static const int kDaysPerMonth[];

        Date() : year(0), month(0), day(0) {};
        Date(int year, int month, int day)
            : year(year), month(month), day(day) {};

        bool        isValid();
        std::time_t convertToEpoch() const;
        std::string convertToString() const;
    };

    typedef std::map<std::time_t, double> ExchangeRateMap;

    bool loadDatabase(const std::string& filename);

    double getExchangeRate(const std::string Date) const;
    double getExchangeRate(std::time_t Date) const;

    ExchangeRateMap getExchangeRates() const;

   private:
    ExchangeRateMap _exchangeRates;

    void processLine(const std::string& line) throw();
    Date parseDate(const std::string& str);
};

#endif
