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
#include "Logger.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testInvalidForm() {}

void testShrubberyCreationForm() {
    AForm* test = new ShrubberyCreationForm();
    AForm* test1 = new ShrubberyCreationForm("28B", "poppy");

    std::cout << (*test);
    std::cout << (*test1);

    delete test;
    test = test1;

    std::cout << "\n" << *test;

    delete test1;
}

void testPresidentialPardonForm() {
    try {
        PresidentialPardonForm form = PresidentialPardonForm("Admiral zelo");
        Bureaucrat             President = Bureaucrat("president", 1);
        Bureaucrat             randall = Bureaucrat("Randall", 146);
        Bureaucrat             randall_brother = Bureaucrat("Randall's big brother", 22);
        
        std::cout << "==== PresidePresidentialPardonForm ====\n";
        std::cout << "\n" << form;

        std::cout << "\nRandall trying to exec...\n";
        randall.executeForm(form);
        std::cout << "ah yes..\n";
        randall.signForm(form);
        std::cout << "Damnit you do it...\n";
        randall_brother.signForm(form);
        randall_brother.executeForm(form);
        std::cout << "We don't have the power...\n";
        std::cout << "Papa * randall get kicked *. Master could you do it please...\n";
        President.executeForm(form);

        std::cout << "\n";
        std::cout << form;
    } catch (std::exception& e) {
        std::cerr << "runtime error: PresidentialPardonForm: " << e.what() << "\n";
    }
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);
    // testShrubberyCreationForm();
    testPresidentialPardonForm();
    return 0;
}
