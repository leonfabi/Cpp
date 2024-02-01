/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:48:31 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/01 20:54:26 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
class MateriaSource: public IMateriaSource{
    private:
        AMateria*   _source[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &old_obj);
        MateriaSource& operator=(const MateriaSource &old_obj);

        void  learnMateria(AMateria* m);
        AMateria*  createMateria(const std::string& type);
};
#endif
