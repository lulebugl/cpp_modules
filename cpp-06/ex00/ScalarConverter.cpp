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

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    ConversionResult   result;
    std::istringstream iss(literal);

    LiteralType type = determineType(literal);

    switch (type) {
        case TYPE_CHAR: {
            result = convertFromChar(literal);
            break;
        }
        case TYPE_INTEGER: {
            result = convertFromInt(literal);
            break;
        }
        case TYPE_FLOAT: {
            result = convertFromFloat(literal);
            break;
        }
        case TYPE_DOUBLE: {
            result = convertFromDouble(literal);
            break;
        }
        default: {
            result = convertFromSpecial(literal);
            break;
        }
    }

    printChar(result);
    printInt(result);
    printFloat(result);
    printDouble(result);
}

ScalarConverter::LiteralType ScalarConverter::determineType(
    const std::string& literal) {
    if (literal.empty())
        return TYPE_STRING;

    if ((literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') ||
        (literal.length() == 1 && !std::isdigit(literal[0])))
        return TYPE_CHAR;

    if (literal == "nan" || literal == "+nan" || literal == "-nan" ||
        literal == "inf" || literal == "+inf" || literal == "-inf" ||
        literal == "nanf" || literal == "+nanf" || literal == "-nanf" ||
        literal == "inff" || literal == "+inff" || literal == "-inff")
        return TYPE_SPECIAL;

    if (literal.length() > 1 && (literal[literal.length() - 1] == 'f' ||
                                 literal[literal.length() - 1] == 'F')) {
        std::istringstream iss(literal.substr(0, literal.length() - 1));
        float              floatVal;
        iss >> floatVal;

        if (iss.eof() && !iss.fail())
            return TYPE_FLOAT;
    }

    {
        std::istringstream iss(literal);
        int                intVal;
        iss >> intVal;

        if (iss.eof() && !iss.fail())
            return TYPE_INTEGER;
    }

    {
        std::istringstream iss(literal);
        double             doubleVal;
        iss >> doubleVal;

        if (iss.eof() && !iss.fail())
            return TYPE_DOUBLE;
    }

    return TYPE_STRING;
}

ScalarConverter::ConversionResult ScalarConverter::convertFromChar(
    const std::string& literal) {
    ConversionResult result;

    if (literal.length() == 1) {
        result.isCharValid = true;
        result.isIntValid = true;
        result.isFloatValid = true;
        result.isDoubleValid = true;

        result.charValue = literal[0];
        result.intValue = static_cast<int>(literal[0]);
        result.floatValue = static_cast<float>(literal[0]);
        result.doubleValue = static_cast<double>(literal[0]);
    }

    return result;
}

ScalarConverter::ConversionResult ScalarConverter::convertFromInt(
    const std::string& literal) {
    ConversionResult result;

    std::istringstream iss(literal);
    iss >> result.intValue;

    if (!iss.fail() && iss.eof()) {
        result.isIntValid = true;
        result.charValue = static_cast<char>(result.intValue);
        result.isCharValid = (result.intValue >= 0 && result.intValue <= 127);
        result.floatValue = static_cast<float>(result.intValue);
        result.isFloatValid = true;
        result.doubleValue = static_cast<double>(result.intValue);
        result.isDoubleValid = true;
    }

    return result;
}

ScalarConverter::ConversionResult ScalarConverter::convertFromFloat(
    const std::string& literal) {
    ConversionResult result;

    std::string floatStr = literal;
    if (floatStr[floatStr.length() - 1] == 'f' ||
        floatStr[floatStr.length() - 1] == 'F')
        floatStr =
            floatStr.substr(0, floatStr.length() - 1);  // removes 'f' suffix

    std::istringstream iss(floatStr);
    iss >> result.floatValue;

    if (!iss.fail() && iss.eof()) {
        result.isFloatValid = true;
        if (result.floatValue >= 0 && result.floatValue <= 127) {
            result.charValue = static_cast<char>(result.floatValue);
            result.isCharValid = true;
        }
        if (result.floatValue >= std::numeric_limits<int>::min() &&
            result.floatValue <= std::numeric_limits<int>::max()) {
            result.intValue = static_cast<int>(result.floatValue);
            result.isIntValid = true;
        }
        result.doubleValue = static_cast<double>(result.floatValue);
        result.isDoubleValid = true;
    }
    return result;
}

ScalarConverter::ConversionResult ScalarConverter::convertFromDouble(
    const std::string& literal) {
    ConversionResult result;

    std::istringstream iss(literal);
    iss >> result.doubleValue;

    if (!iss.fail() && iss.eof()) {
        result.isDoubleValid = true;
        if (result.doubleValue >= 0 && result.doubleValue <= 127) {
            result.charValue = static_cast<char>(result.doubleValue);
            result.isCharValid = true;
        }
        if (result.doubleValue >= std::numeric_limits<int>::min() &&
            result.doubleValue <= std::numeric_limits<int>::max()) {
            result.intValue = static_cast<int>(result.doubleValue);
            result.isIntValid = true;
        }
        if (result.doubleValue >= -std::numeric_limits<float>::max() &&
            result.doubleValue <= std::numeric_limits<float>::max()) {
            result.floatValue = static_cast<float>(result.doubleValue);
            result.isFloatValid = true;
        }
    }
    return result;
}

ScalarConverter::ConversionResult ScalarConverter::convertFromSpecial(
    const std::string& literal) {
    ConversionResult result;

    if (literal == "nanf" || literal == "+nanf" || literal == "-nanf" ||
        literal == "nan" || literal == "+nan" || literal == "-nan") {
        result.floatValue = std::numeric_limits<float>::quiet_NaN();
        result.isFloatValid = true;
        result.doubleValue = std::numeric_limits<double>::quiet_NaN();
        result.isDoubleValid = true;
    } else if (literal == "inff" || literal == "+inff" || literal == "inf" ||
               literal == "+inf") {
        result.floatValue = std::numeric_limits<float>::infinity();
        result.isFloatValid = true;
        result.doubleValue = std::numeric_limits<double>::infinity();
        result.isDoubleValid = true;
    } else if (literal == "-inff" || literal == "-inf") {
        result.floatValue = -std::numeric_limits<float>::infinity();
        result.isFloatValid = true;
        result.doubleValue = -std::numeric_limits<double>::infinity();
        result.isDoubleValid = true;
    }

    return result;
}

void ScalarConverter::printChar(const ConversionResult& result) {
    std::cout << "char: ";
    if (!result.isCharValid)
        std::cout << "impossible";
    else if (result.charValue < 32 || result.charValue > 126)
        std::cout << "Non displayable";
    else
        std::cout << "'" << result.charValue << "'";
    std::cout << std::endl;
}

void ScalarConverter::printInt(const ConversionResult& result) {
    std::cout << "int: ";
    if (!result.isIntValid)
        std::cout << "impossible";
    else
        std::cout << result.intValue;
    std::cout << std::endl;
}

void ScalarConverter::printFloat(const ConversionResult& result) {
    std::cout << "float: ";
    if (!result.isFloatValid)
        std::cout << "impossible";
    else {
        std::cout << std::fixed << std::setprecision(1) << result.floatValue
                  << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(const ConversionResult& result) {
    std::cout << "double: ";
    if (!result.isDoubleValid)
        std::cout << "impossible";
    else {
        std::cout << std::fixed << std::setprecision(1) << result.doubleValue;
    }
    std::cout << std::endl;
}
