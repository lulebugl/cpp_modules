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

#include <iostream>
#include "Phonebook.hpp"

enum Command { CMD_ADD, CMD_SEARCH, CMD_EXIT, CMD_UNKNOWN };

Command parseCommand(const std::string& input) {
    if (input == "ADD") return CMD_ADD;
    if (input == "SEARCH") return CMD_SEARCH;
    if (input == "EXIT") return CMD_EXIT;
    return CMD_UNKNOWN;
}

// Contact Add() {
//     Contact contact;
//     std::cout << "First name: ";
//     std::cin >> contact.first_name;
//     std::cout << "Last name: ";
//     std::cin >> contact.last_name;
//     std::cout << "Nickname: ";
//     std::cin >> contact.nickname;
//     std::cout << "Phone number: ";
//     // protect phone number
//     std::cin >> contact.phone_number;
//     return contact;
// }

int main(void) {
    PhoneBook phoneBook;
    while (true) {
        std::string input;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::cin >> input;
        Command cmd = parseCommand(input);
        int     idx = 0;

        switch (cmd) {
            case CMD_ADD:
                // Handle add
                break;
            case CMD_SEARCH:
                // Handle search
                break;
            case CMD_EXIT:
                return 0;
            case CMD_UNKNOWN:
                std::cout << "Unknown command" << std::endl;
                break;
        }
        if (++idx > 7) idx = 0;
    }
    return (0);
}
