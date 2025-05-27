/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:21:24 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 15:21:28 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Logger.hpp"

void testInvalidForm() {
    std::cout << "\n--- Testing Form Construction ---\n";
    try {
        Form highForm("TooHighGrade", 0, 50);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try {
        Form lowForm("TooLowGrade", 151, 50);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n";
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    try {
        testInvalidForm();

        Bureaucrat manager("Manager", 50);
        std::cout << manager << std::endl;

        Form easyAccess("E75", 75, 75);
        Form restrictedAccess("E25", 25, 25);

        std::cout << "\nForms:\n";
        std::cout << easyAccess << std::endl;
        std::cout << restrictedAccess << std::endl;

        std::cout << "Manager tries to sign " << easyAccess.getName()
                  << " form:\n";
        manager.signForm(easyAccess);
        std::cout << "Not sure he signed, tries again...\n";
        manager.signForm(easyAccess);

        std::cout << "\nManager tries to sign " << restrictedAccess.getName()
                  << " form:\n";
        manager.signForm(restrictedAccess);

        std::cout << "\nPromoting manager to Super manager...\n";
        while (manager.getGrade() > 4) {
            try {
                manager.incrementGrade();
            } catch (...) {
                break;
            }
        }
        std::cout << manager << std::endl;

        std::cout
            << "\nManager, now SUPER Manager, tries again to sign E25 form:\n";
        manager.signForm(restrictedAccess);
        std::cout << "nice !\n";

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
