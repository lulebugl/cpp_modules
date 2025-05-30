/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:14:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/30 13:14:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Logger.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
    LOG_DEBUG("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {
    LOG_DEBUG("RobotomyRequestForm Copy constructor called");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
    LOG_DEBUG("RobotomyRequestForm Assignment operator called");
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    LOG_DEBUG("RobotomyRequestForm Destructor called");
}

void RobotomyRequestForm::beExecuted(const Bureaucrat& bureaucrat) const {
    if (bureaucrat.getGrade() > this->getGradeToExec()) {
        throw GradeTooLowException();
    }
    std::cout << "* drilling noise * ";

    std::srand(static_cast<unsigned int>(std::time(NULL)));
    if (std::rand() % 2 == 0) {
        std::cout << this->getTarget()
                  << " has been robotomized!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->getTarget() << " failed!"
                  << std::endl;
    }
}
