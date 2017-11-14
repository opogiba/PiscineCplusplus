#include "Account.class.hpp"
#include "iostream"


int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int			Account::getNbAccounts() { return _nbAccounts; }
int			Account::getTotalAmount() { return _totalAmount; }
int			Account::getNbDeposits() { return _totalNbDeposits; }
int			Account::getNbWithdrawals() { return _totalNbWithdrawals; }

Account::Account() {
	_displayTimestamp();
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_totalNbDeposits +=_nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	std::cout << "index:"<<_accountIndex<<";amount:"<<_amount<<";created\n";
}

Account::Account(int initial_deposit) {
	_displayTimestamp();
	_amount = initial_deposit;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_totalNbDeposits +=_nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	std::cout << "index:"<<_accountIndex<<";amount:"<<_amount<<";created\n";
}
Account::~Account() {
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex<<";amount:"<<_amount<<";closed\n";
}

void Account::_displayTimestamp() {
	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	std::string format = "[%Y%m%d_%I%M%S] ";
	std::strftime(buffer, 80, format.c_str(), timeinfo);
	std::cout << buffer;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:"<<_nbAccounts<<";total:"<<_totalAmount<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals <<'\n';
}
void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<"\n";

}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
 	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	std::cout << "index:"<<_accountIndex<<";p_amount:"<<p_amount<<";deposit:"<<deposit<<";amount:"<<_amount<<";nb_deposits:"<<_nbDeposits<<"\n";
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();

	int p_amount;

	p_amount = _amount;
	if(_amount >= withdrawal)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount = _totalAmount - withdrawal;
		_amount = _amount - withdrawal;
		std::cout << "index:"<<_accountIndex<<";p_amount:"<<p_amount<<";withdrawal:"<<withdrawal<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<"\n";
		return (true);
	}
	else
	{
		std::cout << "index:"<<_accountIndex<<";p_amount:"<<p_amount<<";withdrawal:refused\n";
		return (false);
	}

}