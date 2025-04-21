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

   public:
    Fixed(void);
    Fixed(const int number);
    Fixed(const float number);
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed();

    int   toInt() const;
    float toFloat() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
