/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:18:23 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 15:18:23 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Form.hpp"
#include "Logger.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    LOG_DEBUG("Bureaucrat constructor called");
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade) {
    LOG_DEBUG("Bureaucrat Copy constructor called");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    LOG_DEBUG("Bureaucrat Assignment operator called");
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() { LOG_DEBUG("Bureaucrat Destructor called"); }

int                Bureaucrat::getGrade() const { return _grade; }
const std::string& Bureaucrat::getName() const { return _name; }

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm(Form& form) const {
    if (form.getSignedStatus()) {
        std::cout << form.getName() << " is already signed\n";
        return ;
    }
    try {
        form.beSigned(*this);
    } catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
        return ;
    }
    std::cout << _name << " signed " << form.getName() << "\n";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade "
        << bureaucrat.getGrade() << ".";
    return out;
}
