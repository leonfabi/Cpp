/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:20:00 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/01 20:30:33 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character: public ICharacter{
    private:
        static const int size = 4;
        int         _t_idx;
        std::string _name;
        AMateria* _inventory[size];
        AMateria* _trash[size];
    public:
        Character();
        Character(std::string const & name);
        ~Character();
        Character(const Character &old_obj);
        Character& operator=(const Character &old_obj);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};
#endif

