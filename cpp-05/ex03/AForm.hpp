/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
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

class AForm {
   public:
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    virtual const std::string& getName() const;
    virtual const std::string& getTarget() const;
    virtual bool               isSigned() const;
    virtual int                getGradeToSign() const;
    virtual int                getGradeToExec() const;

    virtual void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(const Bureaucrat& executor) const;
    virtual void beExecuted() const = 0;

    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

   protected:
    explicit AForm(const std::string& name, int gradeToSign, int gradeToExec,
                   const std::string& target);

   private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExec;
    const std::string _target;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
