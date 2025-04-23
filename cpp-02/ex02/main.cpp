/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 22:36:38 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/21 22:36:40 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void) {
    // Fixed::disableDebug();

    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);
    Fixed e = Fixed(5.05f);

    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int 10): " << b << std::endl;
    std::cout << "c (float 42.42): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;
    std::cout << "e (float 5.05): " << e << std::endl;

    std::cout << "\n===== CONVERSION METHODS =====\n";
    std::cout << "c as int: " << c.toInt() << std::endl;
    std::cout << "c as float: " << c.toFloat() << std::endl;

    std::cout << "\n===== COMPARISON OPERATORS =====\n";
    std::cout << "b == d: " << (b == d ? "true" : "false") << std::endl;
    std::cout << "b != c: " << (b != c ? "true" : "false") << std::endl;
    std::cout << "c > b: " << (c > b ? "true" : "false") << std::endl;
    std::cout << "b < c: " << (b < c ? "true" : "false") << std::endl;
    std::cout << "b >= d: " << (b >= d ? "true" : "false") << std::endl;
    std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;

    std::cout << "\n===== ARITHMETIC OPERATORS =====\n";
    std::cout << "b + c = " << b + c << std::endl;
    std::cout << "c - b = " << c - b << std::endl;
    std::cout << "b * c = " << b * c << std::endl;
    std::cout << "c / b = " << c / b << std::endl;

    std::cout << "\n===== INCREMENT/DECREMENT OPERATORS =====\n";
    Fixed f(1.5f);
    std::cout << "f: " << f << std::endl;
    std::cout << "++f: " << ++f << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "f++: " << f++ << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "--f: " << --f << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "f--: " << f-- << std::endl;
    std::cout << "f: " << f << std::endl;

    std::cout << "\n===== MIN/MAX FUNCTIONS =====\n";
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

    // Test const min/max
    const Fixed const_b(10);
    const Fixed const_c(42.42f);
    std::cout << "min(const_b, const_c): " << Fixed::min(const_b, const_c)
              << std::endl;
    std::cout << "max(const_b, const_c): " << Fixed::max(const_b, const_c)
              << std::endl;

    // test from subject
    // Fixed x;
    // Fixed const y(Fixed(5.05f) * Fixed(2));

    // std::cout << x << std::endl;
    // std::cout << ++x << std::endl;
    // std::cout << x << std::endl;
    // std::cout << x++ << std::endl;
    // std::cout << x << std::endl;
    // std::cout << y << std::endl;
    // std::cout << Fixed::max(x, y) << std::endl;
    //
    return 0;
}
