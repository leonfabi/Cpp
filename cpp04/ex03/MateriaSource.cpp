/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:54:33 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/02 16:06:21 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout << "MateriaSource default constructor called\n";
    for (int i = 0; i < 4; i++)
    {
        _source[i] = NULL;
    }
}

MateriaSource::~MateriaSource(){
    std::cout << "MateriaSource destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (_source[i] != NULL)
            delete _source[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &old_obj){
    for (int i = 0; i < 4; i++){
        _source[i] = NULL;
    }
    *this = old_obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &old_obj){
    if (this!=&old_obj){
        for (int i = 0; i < 4; i++)
        {
            if (_source[i] != NULL){
                delete _source[i];
                _source[i] = NULL;
            }
            if (old_obj._source[i] != NULL)
                _source[i] = old_obj._source[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m){
    for (int i = 0; i < 4; i++)
    {
        if (_source[i] == NULL){
            _source[i] = m;
            return ;
        }
    }
    std::cout << "No spots for new materials available\n";
}

AMateria* MateriaSource::createMateria(const std::string& type){
    for (int i = 0; i < 4; i++)
    {
        if (_source[i] != NULL && _source[i]->getType() == type)
            return _source[i]->clone();
    }
    return NULL;
}