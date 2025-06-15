/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:48:52 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/10 18:49:24 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iomanip>
#include <iostream>

#include "RPN.hpp"

void testCase(const std::string& expression) {
    try {
        double result = RPN::compute(expression);

        std::cout << "\"" << expression << "\"" << " = " << static_cast<long long>(result) << "\n";
    } catch (const std::exception& e) {
        std::string arg = "[" + expression + "]";
        std::cout << std::left << std::setw(12) << arg << " -> " << e.what()
                  << "\n";
    }
}

void additionalTest() {
    testCase("5-3");
    testCase("5 -3");
    testCase("-5-3");
    testCase("--5");
    testCase("5 -");
    testCase("- 5");

    testCase("+");
    testCase("5 + +");
    testCase("5 + * 2");
    testCase("*");

    testCase("0 0 /");
    testCase("5 0 /");
    testCase("-5 0 /");

    testCase("5 3");
    testCase("1 2 3");
    testCase("5 3 + 2");

    testCase("5 3 #");
    testCase("5 3 a");
    testCase("a 3 +");
    testCase("5 3.5 +");

    std::cout << "\n=== Valid expression ===\n";
    testCase("1 2 + 3 *");
    testCase("8 9 * 9 - 9 - 9 - 4 - 1 +");
    testCase("-1 -2 +");
    testCase("-5 3 - -2 *");
    testCase("9 9 *");
    testCase("9 9 9 9 9 9 9 9 9 9 * * * * * * * * *");
    testCase("0 1 +");
    testCase("-9 -1 +");
    
    std::cout << "\n=== Testing Complete ===\n";
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./RPN 'postfix equation'\n";

        std::string response;
        std::cout << "Run additional tests? (y/n): ";
        std::getline(std::cin, response);
        if (!response.empty() && (response[0] == 'y' || response[0] == 'Y')) {
            std::cout << "\n";
            additionalTest();
        }
        return 0;
    }

    try {
        double result = RPN::compute(static_cast<std::string>(argv[1]));
        std::cout << result << "\n";
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
