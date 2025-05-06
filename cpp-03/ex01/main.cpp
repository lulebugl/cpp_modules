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
#include "ScavTrap.hpp"

int main() {
    ClapTrap Chirpy = ClapTrap("Chirpy");
    ScavTrap Scrappy = ScavTrap("Scrappy");

    std::cout << "\n";
    Chirpy.attack("some robots");
    Chirpy.takeDamage(5);
    Chirpy.beRepaired(10);
    Chirpy.beRepaired(5);
    Scrappy.attack("some other robots");
    Scrappy.guardGate();
    std::cout << "\n";

    return 0;
}
