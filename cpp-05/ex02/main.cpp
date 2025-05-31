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
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include <chrono>
// #include <thread>

void testRobotomyRequestForm() {
    try {
        RobotomyRequestForm form("Bender");
        Bureaucrat          engineer("engineer", 45);
        Bureaucrat          clerk("clerk", 100);
        Bureaucrat          manager("manager", 25);

        std::cout << "==== RobotomyRequestForm ====\n";
        std::cout << "\n" << form;

        std::cout << "\nClerk trying to sign...\n";
        clerk.signForm(form);
        std::cout << "Clerk trying to execute...\n";
        clerk.executeForm(form);

        std::cout << "\nEngineer signing the form...\n";
        engineer.signForm(form);
        std::cout << "Engineer executing the form...\n";
        engineer.executeForm(form);

        // std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\nManager trying another execution...\n";
        manager.executeForm(form);

        std::cout << "\n" << form;
    } catch (std::exception& e) {
        std::cerr << "runtime error: RobotomyRequestForm: " << e.what() << "\n";
    }
}

void testShrubberyCreationForm() {
    try {
        ShrubberyCreationForm form("home");
        Bureaucrat            gardener("gardener", 138);
        Bureaucrat            intern("intern", 150);
        Bureaucrat            supervisor("supervisor", 100);

        std::cout << "==== ShrubberyCreationForm ====\n";
        std::cout << "\n" << form;

        std::cout << "\nIntern trying to sign...\n";
        intern.signForm(form);
        std::cout << "Intern trying to execute...\n";
        intern.executeForm(form);

        std::cout << "\nGardener signing the form...\n";
        gardener.signForm(form);
        std::cout << "Gardener trying to execute...\n";
        gardener.executeForm(form);

        std::cout << "\nSupervisor executing the form...\n";
        supervisor.executeForm(form);

        std::cout << "\n" << form;
    } catch (std::exception& e) {
        std::cerr << "runtime error: ShrubberyCreationForm: " << e.what()
                  << "\n";
    }
}

void testPresidentialPardonForm() {
    try {
        PresidentialPardonForm form = PresidentialPardonForm("Admiral zelo");
        Bureaucrat             President = Bureaucrat("president", 1);
        Bureaucrat             randall = Bureaucrat("Randall", 146);
        Bureaucrat randall_brother = Bureaucrat("Randall's big brother", 22);

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
        std::cout << "Papa * randall get kicked *. Master could you do it "
                     "please...\n";
        President.executeForm(form);

        std::cout << "\n";
        std::cout << form;
    } catch (std::exception& e) {
        std::cerr << "runtime error: PresidentialPardonForm: " << e.what()
                  << "\n";
    }
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);
    
    std::srand(static_cast<unsigned int>(std::time(0)));
        
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    return 0;
}
