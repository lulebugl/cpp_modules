/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:14:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/30 13:14:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Logger.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5, (target)) {
    LOG_DEBUG("PresidentialPardonForm constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other) {
    LOG_DEBUG("PresidentialPardonForm Copy constructor called");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
    LOG_DEBUG("PresidentialPardonForm Assignment operator called");
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    LOG_DEBUG("PresidentialPardonForm Destructor called");
}

void PresidentialPardonForm::beExecuted(const Bureaucrat& bureaucrat) const {
    if (bureaucrat.getGrade() > this->getGradeToExec()) {
        throw GradeTooLowException();
    }
    std::cout << this->getTarget()
              << " has been pardoned by Zaphod Beeblebrox\n";
}
