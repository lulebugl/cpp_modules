/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:18:23 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 15:18:23 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
   public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    int                getGrade() const;
    const std::string& getName() const;

    void incrementGrade();
    void decrementGrade();

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
    int               _grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& bureaucrat);

#endif
