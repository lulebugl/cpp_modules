/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:57:29 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/02 17:57:29 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>

enum ValueType {
    // TYPE_CHAR,
    TYPE_STRING,
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_DOUBLE
};

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

ValueType determineValueType(const std::string& value) {
    bool hasDecimalPoint = false;
    bool hasDigits = false;
    bool allDigits = true;

    if (value.empty()) return TYPE_STRING;

    size_t startPos = (value[0] == '-' || value[0] == '+') ? 1 : 0;

    for (size_t i = startPos; i < value.length(); ++i) {
        if (std::isdigit(value[i])) {
            hasDigits = true;
        } else if (value[i] == '.' && !hasDecimalPoint) {
            hasDecimalPoint = true;
        } else {
            allDigits = false;
            break;
        }
    }

    if (!hasDigits) {
        return TYPE_STRING;
    }

    if (allDigits) {
        if (hasDecimalPoint) {
            return TYPE_FLOAT;
        } else {
            return TYPE_INTEGER;
        }
    }

    return TYPE_STRING;
}

ValueType determineType(const std::string& value) {
    std::istringstream iss(value);
    int                intValue;
    iss >> intValue;

    if (iss.eof() && !iss.fail()) {
        return TYPE_INTEGER;
    }

    iss.clear();
    iss.str(value);

    double doubleValue;
    iss >> doubleValue;

    if (iss.eof() && !iss.fail()) {
        return TYPE_DOUBLE;
    }
    
    iss.clear();
    iss.str(value);

    float floatValue;
    iss >> floatValue;

    if (iss.eof() && !iss.fail()) {
        return TYPE_FLOAT;
    } else if (!iss.eof()) {
        std::string leftover;
        iss >> leftover;
        if (leftover[0] == 'f') return TYPE_FLOAT;
    }

    return TYPE_STRING;
}

int convertToInt(const std::string& literal) {
    std::istringstream iss(literal);
    int value;
    iss >> value;
    return value;
}

int convertToFloat(const std::string& literal) {
    std::istringstream iss(literal);
    float value;
    iss >> value;
    return value;
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << literal << std::endl;
    double value;
    std::istringstream iss(literal);
    
    // char   c;
    // int    n;
    // float  f;
    // double d;

    ValueType type = determineType(literal);

    switch (type) {
        case TYPE_INTEGER: {
            value = convertToInt(literal);
            break;
        }
        case TYPE_FLOAT:
            value = convertToFloat(literal);
            std::cout << "The value is a floating-point number." << std::endl;
            break;
        // case TYPE_DOUBLE:
        //     std::cout << "The value is a double." << std::endl;
        //     break;
        // case TYPE_STRING:
        //     std::cout << "The value is a string." << std::endl;
        //     break;
        default: 
            value = 0;
    }
    
    std::cout << "char: " << value << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << value << ".0f" << std::endl;
    // std::cout << "double: impossible" << std::endl;
}
