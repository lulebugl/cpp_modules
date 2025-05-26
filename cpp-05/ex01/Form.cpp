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

#include "Logger.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExec)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    LOG_DEBUG("Form constructor called");
    if (gradeToSign < 1 || gradeToExec < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExec < 150) {
        throw GradeTooHighException();
    }
}

Form::Form(const Form& other) {
    LOG_DEBUG("Form Copy constructor called");
    (void)other;
}

Form& Form::operator=(const Form& other) {
    LOG_DEBUG("Form Assignment operator called");
    if (this != &other) {
        // Copy member variables here
    }
    return *this;
}

Form::~Form() { LOG_DEBUG("Form Destructor called"); }

const std::string& Form::getName() const { return _name; }
bool               Form::getSignedStatus() const { return _signed; }
int                Form::getGradeToSign() const { return _gradeToSign; }
int                Form::getGradeToExec() const { return _gradeToExec; }
