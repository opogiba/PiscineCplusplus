//
// Created by Oleksiy Pogiba on 11/7/17.
//

#ifndef D05_SHRUBBERYCREATIONFORM_HPP
#define D05_SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "fstream"

class ShrubberyCreationForm : public Form{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	void execute(Bureaucrat const & executor) const;
	~ShrubberyCreationForm();

	const int get_signed_grade() const;

};


#endif //D05_SHRUBBERYCREATIONFORM_HPP
