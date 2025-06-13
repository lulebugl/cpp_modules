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

#include <iostream>
#include <sstream>
#include <stack>

void executeOperation(std::stack<int>& exprs, char token) {
    if (exprs.size() < 2) {  // Need at least 2 operands
        throw std::runtime_error("Error: Insufficient operands");
    }
    if (token == '+') {
        int expr1 = exprs.top();
        exprs.pop();
        int expr2 = exprs.top();
        exprs.pop();
        exprs.push(expr1 + expr2);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: ./RPN number ... operations ...\n";
        return 0;
    }

    std::stack<int> exprs;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "+") == 0) {
            try {
                executeOperation(exprs, '+');
            } catch (std::exception& e) {
                std::cerr << e.what() << "\n";
                return 1;
            }
        } else {
            std::stringstream iss(argv[i]);
            int               expr = 0;
            
            iss >> expr;
            if (!iss.fail() && iss.eof()) {
                exprs.push(expr);
            } else {
                std::cerr << "Error: Unable to parse expression: " << argv[i]
                          << "\n";
                return 1;
            }
        }
    }
    std::cout << exprs.top() << "\n";
    return 0;
}
