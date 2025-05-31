/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:47:51 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/31 21:47:51 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>

class AForm;

class Intern {
   public:
    Intern();
    ~Intern();
    AForm* makeForm(const std::string& name, const std::string& target) const;

   private:
    struct formInfo {
        std::string name;
        AForm* (*creator)(const std::string& target);
    };

    static AForm* createShrubberyCreation(const std::string& target);
    static AForm* createRobotomyRequest(const std::string& target);
    static AForm* createPresidentialPardon(const std::string& target);

    static const formInfo forms[];
    static const size_t   formCount;

    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
};

#endif
