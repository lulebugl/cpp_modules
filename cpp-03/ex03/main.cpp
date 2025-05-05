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

#include "DiamondTrap.hpp"

#include <iostream>

int main() {
    DiamondTrap diamond = DiamondTrap("diamond");

    std::cout << "\n";
    diamond.displayStatus();
    
    std::cout << "\n";
    diamond.whoAmI();
    std::cout << "\n";
    
    diamond.attack("john");
    std::cout << "\n";

    return 0;
}
