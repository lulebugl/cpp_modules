/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:58:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 11:58:58 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <string>

#include "AMateria.hpp"
#include "includes/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   public:
    static const int NB_TEMPLATES = 4;
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void      learnMateria(AMateria* m);
    AMateria* createMateria(std::string const& type);

   private:
    AMateria* _templates[NB_TEMPLATES];
};

#endif
