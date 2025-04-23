/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 03:16:06 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/23 03:16:08 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool isOnCorrectSide(const Point& point, const Point& vertex1,
                     const Point& vertex2) {
    Fixed crossProduct =
        ((vertex1.getX() - point.getX()) * (vertex2.getY() - point.getY())) -
        ((vertex1.getY() - point.getY()) * (vertex2.getX() - point.getX()));
    return crossProduct > 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    bool sideAB = isOnCorrectSide(point, a, b);
    bool sideBC = isOnCorrectSide(point, b, c);
    bool sideCA = isOnCorrectSide(point, c, a);

    return (sideAB == sideBC) && (sideBC == sideCA);
}
