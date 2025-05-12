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

#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"

class Character {
   public:
    Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

   private:
};

#endif
