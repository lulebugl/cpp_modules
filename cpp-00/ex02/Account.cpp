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
    struct tm* timeinfo = localtime(&now);

    std::cout << "[" << (timeinfo->tm_year + 1900) << std::setfill('0')
              << std::setw(2) << (timeinfo->tm_mon + 1) << std::setfill('0')
              << std::setw(2) << timeinfo->tm_mday << "_" << std::setfill('0')
              << std::setw(2) << timeinfo->tm_hour << std::setfill('0')
              << std::setw(2) << timeinfo->tm_min << std::setfill('0')
              << std::setw(2) << timeinfo->tm_sec << "] ";
}

void Account::displayStatus(void) const {}
void Account::displayAccountsInfos(void) { 
    _displayTimestamp(); 
    std::cout << "\n";
}

int Account::checkAmount(void) const { return _amount; }

void Account::makeDeposit(int deposit) { ((void)deposit); }
bool Account::makeWithdrawal(int withdrawal) {
    (void)withdrawal;
    return true;
}
