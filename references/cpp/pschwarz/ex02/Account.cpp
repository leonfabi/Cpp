/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:54:11 by pschwarz          #+#    #+#             */
/*   Updated: 2023/05/24 10:11:01 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <time.h>

int Account::_nbAccounts = { 0 };
int Account::_totalAmount = { 0 };
int Account::_totalNbDeposits = { 0 };
int Account::_totalNbWithdrawals = { 0 };

int Account::getNbAccounts(void) {
  return _nbAccounts;
}

int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void printTimestamp(void) {
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[20];

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
  std::cout << buffer;
}

void Account::displayAccountsInfos() {
  printTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
  this->_accountIndex = getNbAccounts();
  _nbAccounts++;
  printTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  _totalAmount += initial_deposit;
  std::cout << "created" << std::endl;
}

Account::~Account() {
  printTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  printTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  this->_amount = this->_amount + deposit;
  std::cout << "amount:" << this->_amount << ";";
  _totalNbDeposits++;
  _totalAmount += deposit;
  this->_nbDeposits++;
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  printTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "withdrawal:";
  if (this->_amount > withdrawal) {
    this->_amount -= withdrawal;
    std::cout << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    this->_nbWithdrawals++;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    return true;
  } else {
    std::cout << "refused" << std::endl;
    return false;
  }
}

int Account::checkAmount(void) const {
  return this->_amount;
}

void Account::displayStatus(void) const {
  printTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
