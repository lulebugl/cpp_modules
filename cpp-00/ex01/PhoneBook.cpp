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

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>

PhoneBook::PhoneBook() {}

Contact PhoneBook::getContact(int index) const {
    if (index < 0 || index > 7) {
        throw std::out_of_range("Contact index out of range.");
    }
    if (_contact[index].getFirstName() == "") {
        throw std::out_of_range("Contact doesn't exists.");
    }
    return _contact[index];
}

std::string parseInputField(std::string fieldname) {
    std::string fieldInput;
    std::cin.clear();
    std::cout << "Enter " << fieldname << ": ";
    if (!std::getline(std::cin, fieldInput)) {
        if (std::cin.eof()) exit(0);
        std::cin.clear();
        return "";
    }
    return fieldInput;
}

void PhoneBook::addContact(int index) {
    Contact     contact;
    std::string field;
    while (true) {
        field = parseInputField("firstname");
        if (contact.setFirstName(field)) break;
    }
    while (true) {
        field = parseInputField("lastname");
        if (contact.setLastName(field)) break;
    }
    while (true) {
        field = parseInputField("nickname");
        if (contact.setNickname(field)) break;
    }
    while (true) {
        field = parseInputField("phone number");
        if (contact.setPhoneNumber(field)) break;
    }
    while (true) {
        field = parseInputField("darkest secret");
        if (contact.setSecret(field)) break;
    }
    _contact[index] = contact;
}

void PhoneBook::displayContactInfo(const Contact &contact) const {
    std::cout << "First name     : " << contact.getFirstName() << "\n";
    std::cout << "Last name      : " << contact.getLastName() << "\n";
    std::cout << "nickname       : " << contact.getNickname() << "\n";
    std::cout << "Phone number   : " << contact.getPhoneNumber() << "\n";
    std::cout << "Darkest secret : " << contact.getSecret() << "\n";
}

void PhoneBook::displayContactList() const {
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
    std::cout << "│   Index  │First Name│ Last Name│ Nickname │\n";
    std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";
    for (int i = 0; i < 8; i++) {
        std::cout << "│" << std::setw(10) << i << "│";
        std::string firstname = _contact[i].getFirstName();
        if (firstname.size() > 10) firstname = firstname.substr(0, 9) + '.';
        std::string lastname = _contact[i].getLastName();
        if (lastname.size() > 10) lastname = lastname.substr(0, 9) + '.';
        std::string nickname = _contact[i].getNickname();
        if (nickname.size() > 10) nickname = nickname.substr(0, 9) + '.';
        std::cout << std::setw(10) << firstname << "│";
        std::cout << std::setw(10) << lastname << "│";
        std::cout << std::setw(10) << nickname << "│\n";
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";
}
