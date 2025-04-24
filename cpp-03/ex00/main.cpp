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

    biz.attack("lazar");
    biz.takeDamage(5);
    biz.beRepaired(10);
    biz.takeDamage(-15);
    biz.beRepaired(5);
    lazar.attack("biz");
    lazar.beRepaired(2);
    lazar.beRepaired(3);
    lazar.beRepaired(4);
    lazar.beRepaired(5);
    lazar.beRepaired(6);
    lazar.beRepaired(7);
    lazar.beRepaired(8);
    lazar.beRepaired(9);
    lazar.beRepaired(10);
    lazar.beRepaired(11);

    return 0;
}
