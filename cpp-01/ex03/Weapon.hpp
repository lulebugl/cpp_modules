/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 03:01:41 by llebugle          #+#    #+#             */
/*   Updated: 2025/04/14 03:01:42 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
   private:
    std::string _type;

   public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    void        setType(const std::string& type);
    std::string getType() const;
};

#endif
