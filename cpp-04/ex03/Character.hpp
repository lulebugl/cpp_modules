/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:57:11 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:57:11 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"
#include "includes/ICharacter.hpp"

class Character : public ICharacter {
   public:
    static const int INVENTORY_SLOTS = 4;
    Character();
    Character(const std::string& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string const& getName() const;
    void               equip(AMateria* m);
    void               unequip(int idx);
    void               use(int idx, ICharacter& target);

   private:
    std::string _name;
    AMateria*   _inventory[INVENTORY_SLOTS];
};

#endif
