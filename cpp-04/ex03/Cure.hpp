/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:38:55 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:38:55 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>

#include "AMateria.hpp"

class Cure : public AMateria {
   public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();
    
    AMateria*  clone() const;
    
};

#endif
