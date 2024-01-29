/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:40:32 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/29 15:33:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#define MEMORY 100

class Brain{
    private:
        std::string _ideas[MEMORY];
        int         _position;
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &old_obj);
        Brain& operator=(const Brain &old_obj);
        void add_idea(std::string idea);
        void print_brain(void) const;
};
#endif