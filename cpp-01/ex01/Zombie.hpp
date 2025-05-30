/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:19:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/13 21:19:59 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie {
   private:
    std::string _name;

   public:
    Zombie();
    explicit Zombie(const std::string& name);
    ~Zombie();
    void announce(void) const;
    void setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
