/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:07:59 by fkrug             #+#    #+#             */
/*   Updated: 2023/12/18 16:34:14 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account( int initial_deposit )
{
	
}

Account::Account(void)
{
	_displayTimestamp();
}

Account::~Account(void)
{
	_displayTimestamp();
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << ltm->tm_year + 1900
	<< ltm->tm_mon + 1 << ltm->tm_mday << "_" 
	<< ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] " << std::endl;
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

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
		return false;
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return true;
	}
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;