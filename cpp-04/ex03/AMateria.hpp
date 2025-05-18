/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 08:30:15 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:30:15 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
   public:
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    AMateria(std::string const& type);
    std::string const& getType() const;
    virtual AMateria*  clone() const = 0;
    virtual void       use(ICharacter& target) = 0;

   protected:
    AMateria();
    std::string _type;

   private:
};

#endif
