/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:54:54 by fkrug             #+#    #+#             */
/*   Updated: 2024/01/30 17:54:58 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <iostream>
#include <string>
class IMateriaSource{
    private:
        std::string    type;
    public:
        IMateriaSource();
        ~IMateriaSource();
        IMateriaSource(const IMateriaSource &old_obj);
        IMateriaSource& operator=(const IMateriaSource &old_obj);
};
#endif

IMateriaSource::IMateriaSource(){
    std::cout << "IMateriaSource default constructor called\n";
}

IMateriaSource::~IMateriaSource(){
    std::cout << "IMateriaSource destructor called\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource &old_obj){
    *this = old_obj;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &old_obj){
    if (this!=&old_obj)
        type = old_obj.type;
    return *this;
}