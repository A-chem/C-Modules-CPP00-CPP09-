/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:20:16 by achemlal          #+#    #+#             */
/*   Updated: 2025/08/04 16:12:50 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}
Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
	std::cout <<"index:"<<_accountIndex
        << ";amount:"<<_amount
        << ";created"<< std::endl;
}
Account::~Account()
{
    _displayTimestamp();
	std::cout <<"index:"<<_accountIndex
        <<";amount:"<< _amount
        <<";closed"<< std::endl;
	_nbAccounts--;
};

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts
        <<";total:"<<_totalAmount
        <<";deposits:"<<_totalNbDeposits
        <<";withdrawals:"<<_totalNbWithdrawals<< std::endl;
}


void Account::_displayTimestamp( void )
{
    std::time_t  t = std::time(NULL);
    std::tm* now = std::localtime(&t);
     std::cout << "[" << (now->tm_year + 1900)
              << (now->tm_mon + 1)
              << now->tm_mday << "_"
              << now->tm_hour
              << now->tm_min
              << now->tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
       this->_amount += deposit;
       this->_nbDeposits++;
       _totalAmount+=deposit;
       _totalNbDeposits++;
        _displayTimestamp();
	std::cout << "index:" << _accountIndex 
        << ";p_amount:" << _amount - deposit 
        << ";deposit:" << deposit 
        << ";amount:" << _amount 
        << ";nb_deposits:" << _nbDeposits << std::endl;
}
void Account::displayStatus(void) const {
    _displayTimestamp();
	std::cout << "index:" << _accountIndex 
        << ";amount:" << _amount 
        << ";deposits:" << _nbDeposits 
        << ";withdrawals:" << _nbWithdrawals << std::endl;

}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex 
    << ";p_amount:" << _amount 
    << ";withdrawal:";
    if(withdrawal < this->_amount)
    {
        _amount -=  withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << withdrawal 
        << ";amount:" << _amount 
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return(true);
    }
		std::cout << "refused" << std::endl;
		return false;
}
int	    Account::checkAmount( void ) const
{
     return this->_amount;
}