/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:34:14 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 12:45:25 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T> void swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T> T& min(T& a, T& b){
    return (a < b) ? a : b;
}

template <typename T> T& max(T& a, T& b){
    return (a > b) ? a : b;
}

#endif