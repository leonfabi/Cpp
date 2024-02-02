/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:00:00 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/02 16:03:35 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void){
    {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    ICharacter* bob = new Character("bob");
    std::cout << "FUNCTIONALITY TEST############################\n";
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->unequip(1);
    me->use(1, *bob);
    me->equip(tmp);
    me->use(1, *bob);
    me->use(4, *bob);
    std::cout << "##############################################\n";
    delete bob;
    delete me;
    delete src;
    }
    {
    Character f("fabi");
    Character m(f);
    AMateria* tmp;
    MateriaSource src;
    src.learnMateria(new Ice());
    tmp = src.createMateria("ice");
    f.equip(tmp);
    std::cout << "COPY TEST############################\n";
    f.use(0, m);
    m.use(0, f);
    m = f;
    m.use(0, f);
    std::cout << "##############################################\n";
    return 0;
    }
}