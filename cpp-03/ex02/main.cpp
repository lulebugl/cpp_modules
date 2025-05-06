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
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main() {
    ClapTrap Zippy = ClapTrap("Zippy");
    ScavTrap Rusty = ScavTrap("Rusty");
    FragTrap Kaboom = FragTrap("Kaboom");

    std::cout << "\n";
    Rusty.displayStatus();
    std::cout << "\n";
    Kaboom.displayStatus();
    std::cout << "\n";
    Zippy.attack("Rusty");
    Zippy.takeDamage(5);
    Zippy.beRepaired(10);
    Zippy.beRepaired(5);
    Rusty.attack("Zippy");
    Rusty.guardGate();
    Kaboom.highFivesGuys();
    Kaboom.takeDamage(101);
    Kaboom.highFivesGuys();
    std::cout << "\n";

    return 0;
}
