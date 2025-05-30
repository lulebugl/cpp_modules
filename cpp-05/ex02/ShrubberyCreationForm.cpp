/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:14:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/30 13:14:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include "Logger.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyForm", 145, 137, "") {
    LOG_DEBUG("Default ShrubberyCreationForm constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name,
                                             const std::string& target)
    : AForm(name, 145, 137, target) {
    LOG_DEBUG("Form constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {
    LOG_DEBUG("ShrubberyCreationForm Copy constructor called");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
    LOG_DEBUG("ShrubberyCreationForm Assignment operator called");
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    LOG_DEBUG("ShrubberyCreationForm Destructor called");
}

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat) {
    (void)bureaucrat;
    return;
}
