#include "Account.hpp"

void	_displayTimestamp( void )
{
    std::time_t t = std::time(0);
    std::tm* timeInfo = std::localtime(&t);
    std::cout << (1900 + timeInfo->tm_year)
              << std::setw(2) << std::setfill('0') << (1 + timeInfo->tm_mon)
              << std::setw(2) << std::setfill('0') << timeInfo->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << timeInfo->tm_hour
              << std::setw(2) << std::setfill('0') << timeInfo->tm_min
              << std::setw(2) << std::setfill('0') << timeInfo->tm_sec;
    std::cout << std::endl;
}

int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	
}

Account::Account()
{
}

Account::~Account( void )
{
}

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

// void	Account::displayAccountsInfos( void )
// {
// }


