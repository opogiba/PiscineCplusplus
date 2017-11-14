#include <iostream>

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat A = Bureaucrat( "Bureaucrat", 1);
	std::cout << A;
	while (1)
	{
		try {
			std::cout << "Bureaucrat -50 grade"<< std::endl;
			A -= 50;
			std::cout << A;
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
			break;

		}

	}

	std::cout << A;
	while (1)
	{
		try {
			std::cout << "Bureaucrat +50 grade"<< std::endl;
			A += 50;
			std::cout << A;
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
			break;

		}

	}
	return 0;
}
