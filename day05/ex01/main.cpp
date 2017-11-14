#include <iostream>

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat A = Bureaucrat( "Alex", 1);
	Form B = Form ("List1", 20, 100);
	std::cout << A;
	while (1)
	{
		try {

			A -= 50;

		}
		catch (std::exception & e){

			break;

		}

	}

	std::cout << A;
	while (1)
	{
		try {
			std::cout << "Bureaucrat +50 grade"<< std::endl;
			A += 50;
			A.signForm(B);
			std::cout << A;
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
			break;

		}

	}
	A.signForm(B);

	Bureaucrat D = Bureaucrat( "Alex 2", 100);
	Form C = Form ("List1", 20, 100);
	std::cout << D;
	while (1)
	{
		try {

			D += 45;
			C.beSigned(D);

		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;

			D += 45;
			std::cout << D;
			C.beSigned(D);


			break;

		}

	}
	return 0;
}
