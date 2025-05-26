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
#include "Logger.hpp"

void testInvalidConstructor() {
    std::cout << "\n--- testing invalid constructor parameters---\n";
    try {
        Bureaucrat test = Bureaucrat(NULL, 150);
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << "\n";
    }
    try {
        Bureaucrat testMax = Bureaucrat("test", -1);
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << "\n";
    }
    try {
        Bureaucrat test = Bureaucrat("test", 151);
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << "\n";
    }
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    Bureaucrat paul = Bureaucrat("Paul", 50);
    Bureaucrat bill = Bureaucrat("Bill", 3);

    std::cout << "The employees:\n";
    std::cout << paul << "\n";
    std::cout << bill << "\n";

    paul = bill;
    std::cout << "\n"
              << "paul grade strongly increase up in contact with bill!\n";
    std::cout << paul << "\n";
    std::cout << bill << "\n";

    std::cout << "\nTeaching Paul as increased bill grades to the max!\n";
    while (true) {
        try {
            bill.incrementGrade();
            std::cout << "increasing " << bill.getName() << "'s grade.\n";
        } catch (std::exception& e) {
            std::cerr << "Can't increase more! " << e.what() << "\n";
            break;
        }
    }
    std::cout << bill << "\n";

    Bureaucrat Aqua = Bureaucrat("Aqua", 150);
    std::cout << "\nAqua has joined the company.\n";
    std::cout << Aqua << "\n";
    std::cout
        << "\nUnfortunately she's annoying Paul which is rapidly going mad\n";
    while (true) {
        try {
            paul.decrementGrade();
        } catch (std::exception& e) {
            std::cerr << "Can't decrease more! " << e.what() << "\n";
            break;
        }
    }
    std::cout << paul << "\n";

    testInvalidConstructor();
    return 0;
}
