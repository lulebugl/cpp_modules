/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:36:14 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/24 04:36:15 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap echo = DiamondTrap("Echo");

    std::cout << "\n";
    echo.displayStatus();

    std::cout << "\n";
    echo.whoAmI();
    std::cout << "\n";

    echo.attack("john");
    std::cout << "\n";

    return 0;
}
