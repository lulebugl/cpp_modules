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

    typedef std::map<time_t, double> ExchangeRateMap;

    bool loadDatabase(const std::string& filename);
    bool loadWallet(const std::string& filename);

    ExchangeRateMap getExchangeRates() const;
    double          getExchangeRate(time_t timestamp) const;

    static std::string timestampToString(time_t timestamp);
    
   private:
    ExchangeRateMap _exchangeRates;

    struct Date {
        int year;
        int month;
        int day;

        static const int kDaysPerMonth[];

        Date() : year(0), month(0), day(0) {};
        Date(int year, int month, int day)
            : year(year), month(month), day(day) {};

        bool        isValid() const;
        time_t      convertToEpoch() const;
        std::string convertToString() const;
    };

    Date parseDate(const std::string& str);
    void processLine(const std::string& line);
    bool isValidFile(const std::string& filename);
};

#endif
