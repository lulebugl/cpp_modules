/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:14:46 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 20:14:46 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
   public:
    explicit Form(const std::string& name, int gradeToSign, int gradeToExec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool               getSignedStatus() const;
    int                getGradeToSign() const;
    int                getGradeToExec() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw() { return "Grade is too low!"; }
    };

   private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExec;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
