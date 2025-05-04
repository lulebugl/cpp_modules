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

int main() {
    ClapTrap bob = ClapTrap("bob");
    ScavTrap scav = ScavTrap("scav");
    FragTrap frag = FragTrap("frag");

    std::cout << "\n";
    scav.displayStatus();
    std::cout << "\n";
    frag.displayStatus();
    std::cout << "\n";
    bob.attack("scav");
    bob.takeDamage(5);
    bob.beRepaired(10);
    bob.takeDamage(-15);
    bob.beRepaired(5);
    scav.attack("bob");
    scav.guardGate();
    frag.highFivesGuys();
    frag.takeDamage(101);
    frag.highFivesGuys();
    std::cout << "\n";

    return 0;
}
