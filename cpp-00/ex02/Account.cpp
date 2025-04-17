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

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

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

Account::Account(int initial_deposit) {
    _displayTimestamp();
    this->_accountIndex = _nbAccounts;
    std::cout << "index:" << this->_accountIndex << ";";
    _nbAccounts += 1;
    this->_amount = initial_deposit;
    _totalAmount += initial_deposit;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "created\n";
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed\n";
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";

    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    _totalAmount += deposit;

    this->_nbDeposits += 1;
    std::cout << "nb_deposits:" << _nbDeposits << "\n";
    _totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    if (withdrawal > _amount) {
        std::cout << "withdrawal:refused\n";
        return false;
    }
    std::cout << "withdrawal:" << withdrawal << ";";
    this->_amount -= withdrawal;
    std::cout << "amount:" << this->_amount << ";";
    _totalAmount -= withdrawal;

    this->_nbWithdrawals += 1;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
    _totalNbWithdrawals += 1;

    return true;
}
