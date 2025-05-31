/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:47:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/31 21:47:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreation(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequest(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

const Intern::formInfo Intern::forms[] = {
    {"ShrubberyCreationForm", &createShrubberyCreation},
    {"RobotomyRequestForm", &createRobotomyRequest},
    {"PresidentialPardonForm", &createPresidentialPardon}};

const size_t Intern::formCount = sizeof(forms) / sizeof(forms[0]);

AForm* Intern::makeForm(const std::string& name,
                        const std::string& target) const {
    if (name.empty() || target.empty()) {
        return NULL; 
    }
    for (size_t i = 0; i < Intern::formCount; i++) {
        if (name == Intern::forms[i].name) {
            std::cout << "Intern creates " << name << "\n";
            return Intern::forms[i].creator(target);
        }
    }
    std::cerr << "Couldn't create form. " << name << " form doesn't exist.\n";
    return NULL;
}
