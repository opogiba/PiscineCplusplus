//
// Created by Oleksiy Pogiba on 11/7/17.
//

#ifndef D05_INTERN_HPP
#define D05_INTERN_HPP


#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{

public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);
	Intern & operator=( Intern const &);

	Form * makeForm(std::string form, std::string target);
};


#endif //D05_INTERN_HPP
