/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:04:57 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/01 21:53:58 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Ice: public AMateria{
    public:
        Ice();
        ~Ice();
        Ice(const Ice &old_obj);
        Ice& operator=(const Ice &old_obj);

        AMateria* clone() const;
        void use(ICharacter& target);
};
#endif

