/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeInfo.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:04:51 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/18 11:57:46 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEINFO_HPP
#define TYPEINFO_HPP
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <exception>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif