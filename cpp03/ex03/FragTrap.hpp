/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:08:55 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/22 15:18:40 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap{
	public:
		FragTrap(std::string name);
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap &old_obj);
		FragTrap& operator=(const FragTrap &old_obj);
		void highFivesGuys(void) const;
};