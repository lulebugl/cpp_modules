/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:21:24 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/26 15:21:28 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Logger.hpp"

void testInvalidForm() {
}
    
int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    AForm *test = new ShrubberyCreationForm();
    AForm *test1 = new ShrubberyCreationForm("28B", "poppy");
        
    std::cout << (*test);
    std::cout << (*test1);
    
    delete test;
    test = test1;
    
    std::cout << "\n" << *test;
    
    delete test1;
    return 0;
}
