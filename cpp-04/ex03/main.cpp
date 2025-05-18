/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:34:28 by llebugle          #+#    #+#             */
/*   Updated: 2025/05/12 08:59:17 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Logger.hpp"
#include "MateriaSource.hpp"
#include "includes/ICharacter.hpp"
#include "includes/IMateriaSource.hpp"

void testSubjectExample() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void testMateriaCloning() {
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    std::cout << "Original Ice type: " << ice->getType() << std::endl;
    std::cout << "Original Cure type: " << cure->getType() << std::endl;

    AMateria* iceClone = ice->clone();
    AMateria* cureClone = cure->clone();

    std::cout << "Cloned Ice type: " << iceClone->getType() << std::endl;
    std::cout << "Cloned Cure type: " << cureClone->getType() << std::endl;

    delete ice;
    delete cure;
    delete iceClone;
    delete cureClone;
}

void testMateriaSource() {
    std::cout << "\n===== MATERIA SOURCE TEST =====\n";

    IMateriaSource* src = new MateriaSource();

    std::cout << "Learning Ice and Cure materias...\n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "Creating materias from templates...\n";
    AMateria* ice = src->createMateria("ice");
    AMateria* cure = src->createMateria("cure");
    AMateria* unknown = src->createMateria("fireball");

    std::cout << "Ice created: " << (ice ? "yes" : "no") << std::endl;
    std::cout << "Cure created: " << (cure ? "yes" : "no") << std::endl;
    std::cout << "Unknown created: " << (unknown ? "yes" : "no") << std::endl;

    std::cout << "\nTrying to learn more than 4 materias...\n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());

    delete ice;
    delete cure;
    delete src;
}

void testCharacterActions() {
    std::cout << "\n===== CHARACTER TEST =====\n";

    AMateria* floor[10] = {NULL};
    int       floorIndex = 0;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Character* me = new Character("Jean Claude Van Damme");
    Character* target = new Character("Trump");

    std::cout << "Created characters: " << me->getName() << " and "
              << target->getName() << std::endl;

    std::cout << "\nEquipping materias...\n";
    AMateria* m1 = src->createMateria("ice");
    AMateria* m2 = src->createMateria("cure");
    AMateria* m3 = src->createMateria("ice");
    AMateria* m4 = src->createMateria("cure");
    AMateria* m5 = src->createMateria("cure");  // Won't fit in inventory

    me->equip(m1);
    me->equip(m2);
    me->equip(m3);
    me->equip(m4);
    me->equip(m5);  // Should fail (inventory full)

    std::cout << "\nUsing materias on " << target->getName() << "...\n";
    me->use(0, *target);
    me->use(1, *target);
    me->use(-1, *target);  // Invalid index
    me->use(4, *target);   // Invalid index

    std::cout << "\nUnequipping and re-equipping...\n";
    me->unequip(2);
    floor[floorIndex++] = m3;
    me->use(2, *target);

    me->equip(m5);
    me->use(2, *target);

    std::cout << "\nTesting character copy...\n";
    Character* meCopy = new Character(*me);
    std::cout << "Copy name: " << meCopy->getName() << std::endl;
    std::cout << "Original using materia 0:\n";
    me->use(0, *target);
    std::cout << "Copy using materia 0:\n";
    meCopy->use(0, *target);

    delete me;
    delete meCopy;
    delete target;
    delete src;

    for (int i = 0; i < floorIndex; i++) {
        if (floor[i]) {
            delete floor[i];
        }
    }
}

int main() {
    Logger::setLevel(LOG_LEVEL_INFO);

    // testSubjectExample();
    testMateriaCloning();
    testMateriaSource();
    testCharacterActions();

    return 0;
}
