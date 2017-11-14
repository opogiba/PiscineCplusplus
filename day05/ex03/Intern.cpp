//
// Created by Oleksiy Pogiba on 11/7/17.
//

#include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern( Intern const & src )
{
	*this = src;
}

Intern & Intern::operator=( Intern const &)
{
	return *this;
}

Intern::~Intern( void ) {}

Form * Intern::makeForm(std::string form, std::string target)
{
	if (form == "robotomy request")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "shrubbery creation")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (form == "presidential pardon")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	}
	std::cout << "Requested form unknown." << std::endl;
	return (NULL);
}