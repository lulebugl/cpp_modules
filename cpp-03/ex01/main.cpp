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
    ClapTrap biz = ClapTrap("biz");
    ScavTrap karen = ScavTrap("karen");

    std::cout << "\n";
    biz.attack("karen");
    biz.takeDamage(5);
    biz.beRepaired(10);
    biz.takeDamage(-15);
    biz.beRepaired(5);
    karen.attack("biz");
    karen.guardGate();
    std::cout << "\n";

    return 0;
}
