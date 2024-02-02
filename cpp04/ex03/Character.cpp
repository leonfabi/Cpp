/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:20:27 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/02 16:03:45 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("default"), _t_idx(0){
    std::cout << "Character default constructor called\n";
    for (int i = 0; i < size; i++){
        _inventory[i] = NULL;
        _trash[i] = NULL;
    }
}

Character::Character(std::string const & name): _name(name), _t_idx(0){
    std::cout << "Character constructor called: " << name << " \n";
    for (int i = 0; i < size; i++){
        _inventory[i] = NULL;
        _trash[i] = NULL;
    }
}

Character::~Character(){
    for (int i = 0; i < size; i++){
        if (_inventory[i] != NULL)
            delete _inventory[i];
        if (_trash[i] != NULL)
            delete _trash[i];
    }
    std::cout << "Character destructor called\n";
}

Character::Character(const Character &old_obj){
    for (int i = 0; i < size; i++)
    {
        _inventory[i] = NULL;
        _trash[i] = NULL;
    }
    *this = old_obj;
}

Character& Character::operator=(const Character &old_obj){
    if (this!=&old_obj){
        _name = old_obj._name;
        _t_idx = old_obj._t_idx;
        for (int i = 0; i < size; i++){
            if (_inventory[i] != NULL){
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (old_obj._inventory[i] != NULL)
                _inventory[i] = old_obj._inventory[i]->clone();
            if (_trash[i] != NULL){
                delete _trash[i];
                _trash[i] = NULL;
            }
            if (old_obj._trash[i] != NULL)
                _trash[i] = old_obj._trash[i]->clone();
        }
    }
    return *this;
}

std::string const & Character::getName() const{
    return _name;
}

void Character::use(int idx, ICharacter& target){
    if (idx >= 0 && idx < size && _inventory[idx] != NULL)
        _inventory[idx]->use(target);
    else if (idx >= 0 && idx < size)
        std::cout << "No item at this index\n";
    else
        std::cout << "Index out of range\n";
}

void Character::equip(AMateria* m){
    for (int i = 0; i < size; i++){
        if (!_inventory[i]){
            _inventory[i] = m;
            return ;
        }
    }
    std::cout << "Can't add to inventory, because inventory is full\n";
}

void Character::unequip(int idx){
    if (idx >= size && idx < 0){
        std::cout << "Wrong index\n";
        return ;
    }
    if (_inventory[idx] == NULL){
        std::cout << "Already empty\n";
        return ;
    }
    if (_t_idx == 4)
        _t_idx = 0;
    if (_trash[_t_idx] != NULL)
        delete _trash[_t_idx];
    _trash[_t_idx] = _inventory[idx];
    _inventory[idx] = NULL;
    _t_idx++;
}