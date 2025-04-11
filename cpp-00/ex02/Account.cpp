/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:01:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/11 21:01:59 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iomanip>
#include <iostream>

Account::Account() {}
Account::Account(int) {}

Account::~Account(void) {}

void Account::_displayTimestamp(void) {
    time_t     now = time(0);
    struct tm* timeinfo = gmtime(&now);

    std::cout << timeinfo->tm_year;
    std::cout << timeinfo->tm_mon;
    // std::cout << timeinfo->tm_year;
    // std::cout << timeinfo->tm_year;
    // std::cout << timeinfo->tm_year;
    // std::cout << timeinfo->tm_year;
    // std::cout << timeinfo->tm_year;
    // std::cout << timeinfo->tm_year;
}

void Account::displayStatus(void) const {}
void Account::displayAccountsInfos(void) {}

int Account::checkAmount(void) const { return _amount; }

void Account::makeDeposit(int deposit) { deposit = 0; }
bool Account::makeWithdrawal(int withdrawal) {
    withdrawal = 0;
    return true;
}
