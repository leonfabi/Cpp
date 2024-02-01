/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:11:47 by fkrug             #+#    #+#             */
/*   Updated: 2024/02/01 21:53:38 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
class Cure: public AMateria{
    public:
        Cure();
        ~Cure();
        Cure(const Cure &old_obj);
        Cure& operator=(const Cure &old_obj);

        AMateria* clone() const;
        void use(ICharacter& target);
};
#endif

