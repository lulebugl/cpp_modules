/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:12:20 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/06 20:12:20 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    std::string         getType() const;
    virtual void        makeSound() const;
    virtual void        setIdea(const std::string& idea, int idx);
    virtual std::string getIdea(int idx) const;
    virtual void        showBrain() const;

   protected:
    std::string _type;
};

#endif
