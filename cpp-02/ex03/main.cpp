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

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Fixed::disableDebug();
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point point1(2.5f, 2.0f);
    Point point2(10.0f, 10.0f);
    Point point3(0.0f, 0.0f);
    Point point4(0.01f, 0.01f);
    Point point5(2.4f, 2.02f);

    std::cout << "Point 1 is " << (bsp(a, b, c, point1) ? "inside" : "outside")
              << " the triangle\n";
    std::cout << "Point 2 is " << (bsp(a, b, c, point2) ? "inside" : "outside")
              << " the triangle\n";
    std::cout << "Point 3 is " << (bsp(a, b, c, point3) ? "inside" : "outside")
              << " the triangle\n";
    std::cout << "Point 4 is " << (bsp(a, b, c, point4) ? "inside" : "outside")
              << " the triangle\n";
    std::cout << "Point 5 is " << (bsp(a, b, c, point5) ? "inside" : "outside")
              << " the triangle\n";
    return 0;
}
