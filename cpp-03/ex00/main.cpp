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

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap Chirpy = ClapTrap("Chirpy");
    ClapTrap Zippy = ClapTrap("Zippy");

    std::cout << "\n";
    Chirpy.displayStatus();
    std::cout << "\n";
    Chirpy.attack("WX-777");
    Chirpy.takeDamage(5);
    Chirpy.beRepaired(10);
    Chirpy.beRepaired(5);
    Zippy.attack("WX-777");
    for (int i = 0; i <= 10; i++) {
        Zippy.beRepaired(i);
    }
    std::cout << "\n";

    return 0;
}
