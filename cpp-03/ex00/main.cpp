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

int main() {
    ClapTrap biz = ClapTrap("biz");
    ClapTrap lazar = ClapTrap("lazar");

    std::cout << "\n";
    biz.attack("lazar");
    biz.takeDamage(5);
    biz.beRepaired(10);
    biz.takeDamage(-15);
    biz.beRepaired(5);
    lazar.attack("biz");
    for (int i = 0; i <= 10; i++) {
        lazar.beRepaired(i);
    }
    std::cout << "\n";

    return 0;
}
