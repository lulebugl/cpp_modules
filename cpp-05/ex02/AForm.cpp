/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:14:46 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 20:14:46 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"
#include "Logger.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec,
             const std::string& target)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec),
      _target(target) {
    LOG_DEBUG("Form constructor called");
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExec > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExec(other._gradeToExec),
      _target(other._target) {
    LOG_DEBUG("Form Copy constructor called");
}

AForm& AForm::operator=(const AForm& other) {
    LOG_DEBUG("Form Assignment operator called");
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() { LOG_DEBUG("Form Destructor called"); }

const std::string& AForm::getName() const { return _name; }
const std::string& AForm::getTargetName() const { return _target; }
bool               AForm::getSignedStatus() const { return _signed; }
int                AForm::getGradeToSign() const { return _gradeToSign; }
int                AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "form name: " << form.getName() << "\n"
        << "Signed: " << (form.getSignedStatus() ? "Yes" : "No") << "\n"
        << "Grade to sign: " << form.getGradeToSign() << "\n"
        << "Grade to execute: " << form.getGradeToExec() << "\n"
        << "Target: " << form.getTargetName() << "\n";
    return out;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
