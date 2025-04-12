/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <lucas.lebugle@student.s19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 01:22:27 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/08 02:38:35 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Phonebook.hpp"

enum Command { CMD_ADD, CMD_SEARCH, CMD_EXIT, CMD_UNKNOWN };

Command parseCommand(const std::string& input) {
    if (input == "ADD") return CMD_ADD;
    if (input == "SEARCH") return CMD_SEARCH;
    if (input == "EXIT") return CMD_EXIT;
    return CMD_UNKNOWN;
}

int selectIndex(void) {
    std::string input;
    int         idx;
    while (true) {
        std::cin.clear();
        std::cout << "Select an index: ";
        if (!std::getline(std::cin, input)) {
            if (std::cin.eof()) exit(0);
            std::cin.clear();
            continue;
        }
        if (input.empty()) continue;
        if (input.length() != 1 || !isdigit(input[0])) {
            std::cout << RED << "Invalid index.\n" << RESET;
            continue;
        }
        idx = std::atoi(input.c_str());
        if (idx < 0 || idx > 7) {
            std::cout << RED << "Index out of range.\n" << RESET;
            continue;
        }
        break;
    }
    return (idx);
}

bool executeCommand(PhoneBook& phoneBook, const std::string& commandInput,
                    int& nextContactSlot) {
    Command cmd = parseCommand(commandInput);

    switch (cmd) {
        case CMD_ADD: {
            phoneBook.addContact(nextContactSlot);
            nextContactSlot = (nextContactSlot + 1) % 8;
            break;
        }
        case CMD_SEARCH: {
            if (phoneBook.empty()) {
                std::cout << RED << "Phonebook is empty.\n" << RESET;
                break ;
            }
            phoneBook.displayContactList();
            bool success = false;
            while (!success) {
                try {
                    Contact contact = phoneBook.getContact(selectIndex());
                    phoneBook.displayContactInfo(contact);
                    success = true;
                } catch (const std::out_of_range& e) {
                    std::cout << RED << e.what() << RESET << std::endl;
                };
                if (success) break;
            }
        }
        case CMD_EXIT:
            return false;
        case CMD_UNKNOWN:
            std::cout << "Unknown command\n";
            break;
    }
    return true;
}

int main(void) {
    int       nextContactSlot = 0;
    PhoneBook phoneBook;

    while (true) {
        std::string commandInput;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, commandInput)) {
            if (std::cin.eof()) exit(0);
            std::cin.clear();
            continue;
        }
        if (commandInput.empty()) continue;
        if (!executeCommand(phoneBook, commandInput, nextContactSlot)) break;
    }
    return (0);
}
