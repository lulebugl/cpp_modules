/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:03:26 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 03:03:27 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>

#include "Weapon.hpp"

class HumanA {
   private:
    std::string _name;
    Weapon&     _weapon;

   public:
    HumanA(const std::string& name, Weapon& weapon);
    ~HumanA();

    std::string getName() const;
    std::string getWeapon() const;
    void        setWeaponType(Weapon& weapon);
    void        attack() const;
};

#endif
