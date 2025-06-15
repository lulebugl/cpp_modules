/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:47:16 by llebugle          #+#    #+#             */
/*   Updated: 2025/06/13 12:47:16 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>

class RPN {
   public:
    static double compute(std::string str);

   private:
    struct Operations {
        char op;
        double (*func)(double x, double y);
    };

    static Operations operations[];
    static void       executeOperation(std::stack<double>& stack, char ope);
    static bool       isNegativeDigit(const std::string& str, std::size_t pos);
    static bool       isOperator(char c);
    static double     add(double x, double y);
    static double     subtract(double x, double y);
    static double     multiply(double x, double y);
    static double     divide(double x, double y);

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
};

#endif
