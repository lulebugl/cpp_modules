/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:24:14 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/23 01:24:14 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
   public:
    Point();
    Point(const Point& other);
    Point(const float& x, const float& y);
    Point& operator=(const Point& other);
    ~Point();

    Point operator-(const Point& other) const;

    const Fixed& getX() const;
    const Fixed& getY() const;

   private:
    Fixed const _x;
    Fixed const _y;
    static bool _debugMode;
};

#endif
