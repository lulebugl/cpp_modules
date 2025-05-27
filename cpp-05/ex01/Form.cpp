/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:14:46 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 20:14:46 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include "Logger.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    LOG_DEBUG("Form constructor called");
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExec > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExec(other._gradeToExec) {
    {
        LOG_DEBUG("Form Copy constructor called");
    }
}

Form& Form::operator=(const Form& other) {
    LOG_DEBUG("Form Assignment operator called");
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form() { LOG_DEBUG("Form Destructor called"); }

const std::string& Form::getName() const { return _name; }
bool               Form::getSignedStatus() const { return _signed; }
int                Form::getGradeToSign() const { return _gradeToSign; }
int                Form::getGradeToExec() const { return _gradeToExec; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "form name: " << form.getName() << "\n"
        << "signed: " << (form.getSignedStatus() ? "true" : "false") << "\n"
        << "Grade to sign: " << form.getGradeToSign() << "\n"
        << "Grade to execute: " << form.getGradeToExec() << "\n";
    return out;
}
