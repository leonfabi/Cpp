/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:30:24 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/30 17:56:37 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include <string>
#include "ICharacter.hpp"
class AMateria{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const & type);
        ~AMateria();
        AMateria(const AMateria &old_obj);
        AMateria& operator=(const AMateria &old_obj);
        
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
#endif

