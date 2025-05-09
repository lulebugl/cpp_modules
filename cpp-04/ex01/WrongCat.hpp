/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:54:43 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/09 19:54:43 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <string>

#include "Brain.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();

    void        makeSound() const;
    void        setIdea(const std::string& idea, int idx);
    std::string getIdea(int idx) const;
    void        showBrain() const;

   private:
    Brain* _brain;
};

#endif
