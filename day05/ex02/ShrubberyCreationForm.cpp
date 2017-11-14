//
// Created by Oleksiy Pogiba on 11/7/17.
//

#include "ShrubberyCreationForm.hpp"



ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form()
{
	this->set_target(target);
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : Form()
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

const int ShrubberyCreationForm::get_signed_grade() const {
	return 145;
}




void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string name = this->get_target() + "_shrubbery";
	const char *fileName = name.c_str();
	if (executor.get_grade() <= 137 && this->is_signed() == true)
	{
		std::ofstream ofs(fileName);
		if (ofs)
		{
			ofs << "    O    " << std::endl << "   OOO   " << std::endl << "  OOOOO  " << std::endl << " OOOOOOO " << std::endl << "OOOOOOOOO" << std::endl << "    |    " << std::endl << " XXXXXXX " << std::endl;
		}
		ofs.close();
	}
	else if (this->is_signed() == false)
		std::cout << "The form isn't signed yet." << std::endl;
	else
		throw Form::GradeTooLowException();
}