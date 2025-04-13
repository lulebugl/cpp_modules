/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:11:08 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/13 22:11:09 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0) return nullptr;
    Zombie* horde = new (std::nothrow) Zombie[N];
    if (!horde) return nullptr;
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}
