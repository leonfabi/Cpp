/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:37:12 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 15:44:17 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array& old_obj);
        Array& operator=(const Array& old_obj);
};

#endif