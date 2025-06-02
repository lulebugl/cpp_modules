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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Logger.hpp"
#include <ctime>
#include <cstdlib>

void testFormCreation(const std::string& formName, const std::string& target) {
    Intern     intern;
    Bureaucrat ceo("CEO", 1);

    std::cout << "\n===== Testing " << formName << " =====\n";

    AForm* form = intern.makeForm(formName, target);
    if (!form) {
        std::cerr << "Form creation failed!\n";
        return ;
    }

    std::cout << "\nForm details:\n" << *form << "\n";
    
    ceo.signForm(*form);
    ceo.executeForm(*form);
    delete form;
}


int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    std::srand(static_cast<unsigned int>(std::time(0)));

    try {
        testFormCreation("ShrubberyCreationForm", "garden");
        testFormCreation("RobotomyRequestForm", "Bender");
        testFormCreation("PresidentialPardonForm", "Doug");
        testFormCreation("unknown", "unknown");
    } catch (std::exception& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
