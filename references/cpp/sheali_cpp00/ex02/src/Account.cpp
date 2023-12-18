/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheali <sheali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 03:19:34 by sheali            #+#    #+#             */
/*   Updated: 2023/04/27 16:46:46 by sheali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>
# include <string>

Account::Account( int initial_deposit )
{
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= this->_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(0);
    struct tm *tstruct = localtime(&now);
    char buf[80];
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", tstruct);
    std::cout << buf;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit;

    this->_amount += deposit;
    Account::_totalAmount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;

    std::cout << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";withdrawal:";

    if (this->_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    else
    {
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;

        std::cout << withdrawal << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

        return true;
    }
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;