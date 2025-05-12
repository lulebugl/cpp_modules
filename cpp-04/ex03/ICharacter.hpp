/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:20:21 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 09:20:22 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter {
   public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void               equip(AMateria* m) = 0;
    virtual void               unequip(int idx) = 0;
    virtual void               use(int idx, ICharacter& target) = 0;
};

#endif
