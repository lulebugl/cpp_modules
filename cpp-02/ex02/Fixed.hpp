/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:16:15 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/20 21:16:15 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
   private:
    int              _number;
    static const int _fixedPoint;
    static bool      _debugMode;

   public:
    Fixed(void);
    ~Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);

    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;

    Fixed operator*(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator+(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    Fixed &operator++();     // preincrement
    Fixed  operator++(int);  // postincrement
    Fixed &operator--();
    Fixed  operator--(int);

    static Fixed       &min(Fixed &x, Fixed &y);
    static const Fixed &min(const Fixed &x, const Fixed &y);
    static Fixed       &max(Fixed &x, Fixed &y);
    static const Fixed &max(Fixed const &x, const Fixed &y);

    int   toInt() const;
    float toFloat() const;
    
    static void enableDebug();
    static void disableDebug();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
