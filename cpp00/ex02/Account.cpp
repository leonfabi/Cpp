/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:07:59 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/11 15:22:15 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(void)
{
}

Account::~Account(void)
{
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
void Account::displayAccountsInfos(void)
{
	
}