/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:03:17 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 03:03:18 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>

#include "Weapon.hpp"

class HumanB {
   private:
    std::string _name;
    Weapon*     _weapon;
    HumanB();

   public:
    HumanB(const std::string& name);
    HumanB(const std::string& name, Weapon* weapon);
    ~HumanB();

    std::string getName() const;
    std::string getWeapon() const;
    void        setWeapon(Weapon& weapon);
    void        attack() const;
};

#endif
