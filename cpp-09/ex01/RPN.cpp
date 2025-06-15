/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:47:16 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/13 12:47:16 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <cassert>
#include <stdexcept>
#include <sstream>

RPN::Operations RPN::operations[] = {{'+', RPN::add},
                                     {'-', RPN::subtract},
                                     {'*', RPN::multiply},
                                     {'/', RPN::divide}};

double RPN::compute(std::string arg) {
    std::stack<double> exprs;

    for (size_t i = 0; i < arg.length(); ++i) {
        if (std::isspace(arg[i])) {
            continue;
        }

        if (std::isdigit(arg[i])) {
            exprs.push(arg[i] - '0');  // char to int
        } else if (isNegativeDigit(arg, i)) {
            exprs.push(-(arg[++i] - '0'));
        } else if (isOperator(arg[i])) {
            executeOperation(exprs, arg[i]);
        } else {
            std::stringstream errMsg;
            errMsg << "invalid token: " << arg[i];
            throw std::invalid_argument(errMsg.str());
        }
    }
    if (exprs.size() != 1) {
        throw std::invalid_argument("Invalid format");
    }
    return exprs.top();
}

bool RPN::isNegativeDigit(const std::string& str, std::size_t pos) {
    return (str[pos] == '-' && pos + 1 < str.length() &&
            std::isdigit(str[pos + 1]));
}

void RPN::executeOperation(std::stack<double>& exprs, char token) {
    if (exprs.size() < 2) {  // Need at least 2 operands
        throw std::runtime_error("Invalid format");
    }
    for (std::size_t i = 0; i < sizeof(operations) / sizeof(Operations); i++) {
        if (operations[i].op == token) {
            double expr1 = exprs.top();
            exprs.pop();
            double expr2 = exprs.top();
            exprs.pop();
            exprs.push(operations[i].func(expr2, expr1));
            return;
        };
    }
    assert(false && "Unknown operator passed to executeOperation");
}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

double RPN::add(double x, double y) {
    return x + y;
}
double RPN::subtract(double x, double y) {
    return x - y;
}
double RPN::multiply(double x, double y) {
    return x * y;
}
double RPN::divide(double x, double y) {
    if (y == 0) {
        throw std::logic_error("division by zero");
    }
    return x / y;
}

RPN::RPN() {}
RPN::RPN(const RPN& other) {
    (void)other;
}
RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}
RPN::~RPN() {}
