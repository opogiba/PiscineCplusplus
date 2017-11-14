#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {

	srand(clock());
	Bureaucrat A = Bureaucrat( "Alex", 30);
	PresidentialPardonForm B = PresidentialPardonForm ("hellou");

	std::cout << A << std::endl;
	try {
		A.signForm(B);
		A += 6;
		A.signForm(B);
		A += 10;
		B.execute(A);

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		A += 10;
		B.execute(A);

	}
	std::cout << A << std::endl;


	Bureaucrat D = Bureaucrat( "Bob", 80);
	RobotomyRequestForm C = RobotomyRequestForm ("zzzzzzzzzzzzz");

	std::cout << D << std::endl;
	try {
		D.signForm(C);


		C.execute(D);

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "HI" << std::endl;


	}
	std::cout << D << std::endl;

//	std::cout << A;
//	while (1)
//	{
//		try {
//
//			A -= 50;
//
//		}
//		catch (std::exception & e){
//
//			break;
//
//		}
//
//	}
//
//	std::cout << A;
//	while (1)
//	{
//		try {
//			std::cout << "Bureaucrat +50 grade"<< std::endl;
//			A += 50;
//			A.signForm(B);
//			std::cout << A;
//		}
//		catch (std::exception & e){
//			std::cout << e.what() << std::endl;
//			break;
//
//		}
//
//	}
//	A.signForm(B);
//
//	Bureaucrat D = Bureaucrat( "Alex 2", 100);
//	Form C = Form ("List1", 20, 100);
//	std::cout << D;
//	while (1)
//	{
//		try {
//
//			D += 45;
//			C.beSigned(D);
//
//		}
//		catch (std::exception & e){
//			std::cout << e.what() << std::endl;
//
//			D += 45;
//			std::cout << D;
//			C.beSigned(D);
//
//
//			break;
//
//		}
//
//	}
	return 0;
}
