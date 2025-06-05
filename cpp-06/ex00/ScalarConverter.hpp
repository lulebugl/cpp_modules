/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:57:29 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/02 17:57:29 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
   public:
    static void convert(const std::string& literal);

   private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    enum LiteralType {
        TYPE_CHAR,
        TYPE_STRING,
        TYPE_INTEGER,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_SPECIAL
    };
    
    struct ConversionResult {
        char   charValue;
        int    intValue;
        float  floatValue;
        double doubleValue;

        bool isCharValid;
        bool isIntValid;
        bool isFloatValid;
        bool isDoubleValid;

        ConversionResult()
            : charValue(0),
              intValue(0),
              floatValue(0.0f),
              doubleValue(0.0),
              isCharValid(false),
              isIntValid(false),
              isFloatValid(false),
              isDoubleValid(false) {}
    };

    static LiteralType      determineType(const std::string& literal);
    static ConversionResult convertFromChar(const std::string& literal);
    static ConversionResult convertFromInt(const std::string& literal);
    static ConversionResult convertFromFloat(const std::string& literal);
    static ConversionResult convertFromDouble(const std::string& literal);
    static ConversionResult convertFromSpecial(const std::string& literal);

    // static void printResult(ConversionResult results);
    static void printChar(const ConversionResult& result);
    static void printInt(const ConversionResult& result);
    static void printFloat(const ConversionResult& result);
    static void printDouble(const ConversionResult& result);
};

#endif
