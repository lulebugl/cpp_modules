/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:29:14 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/10 16:29:16 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() {}

Contact PhoneBook::getContact(int idx) const {
    if (idx < 0 || idx > 7) {
        throw std::out_of_range("Contact index out of range");
    }
    return contact[idx];
}

void PhoneBook::displayContacts() const {
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
    std::cout << "│   Index  │First Name│ Last Name│ Nickname │\n";
    std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "│" << std::setw(10) << i << "│";
        std::string firstname = contact[i].getFirstName();
        if (firstname.length() > 10) firstname = firstname.substr(0, 9) + '.';
        std::string lastname = contact[i].getLastName();
        if (firstname.length() > 10) firstname = firstname.substr(0, 9) + '.';
        std::string nickname = contact[i].getNickname();
        if (firstname.length() > 10) firstname = firstname.substr(0, 9) + '.';
        std::cout << std::setw(10) << firstname << "│";
        std::cout << std::setw(10) << lastname << "│";
        std::cout << std::setw(10) << nickname << "│\n";
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";
}
