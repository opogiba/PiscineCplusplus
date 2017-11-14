//
// Created by Oleksiy Pogiba on 11/7/17.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : Form() {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form()
{
	this->set_target(target);
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : Form()
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

const int RobotomyRequestForm::get_signed_grade() const {
	return 72;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.get_grade() <= 45 && this->is_signed() == true)
	{
		std::cout << "ZZZZ *drilling noises*" << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->get_target() << " has been robotomized successfully." << std::endl;
		else
			std::cout << "It's a failure." << std::endl;
	}
	else if (this->is_signed() == false)
		std::cout << "The form isn't signed yet." << std::endl;
	else
		throw Form::GradeTooLowException();
}