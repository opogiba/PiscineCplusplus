//
// Created by Oleksiy Pogiba on 11/7/17.
//

#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm( void ) : Form()
{

}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form()
{
	this->set_target(target);
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : Form()
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}


const int PresidentialPardonForm::get_signed_grade() const {
	return 25;
}




void PresidentialPardonForm::execute(Bureaucrat const & val) const
{
	if (val.get_grade() <= 5 && this->is_signed() == true)
		std::cout << this->get_target() << " has been pardonned by Zafod Beeblebrox." << std::endl;
	else if (this->is_signed() == false)
		std::cout << "The form isn't signed." << std::endl;
	else
		throw Form::GradeTooLowException();
}

