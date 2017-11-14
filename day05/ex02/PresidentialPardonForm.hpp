//
// Created by Oleksiy Pogiba on 11/7/17.
//

#ifndef D05_PRESIDENTIALPARDONFORM_HPP
#define D05_PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"


class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const & var );
	void execute(Bureaucrat const & val) const;
	const int get_signed_grade() const;
	~PresidentialPardonForm();

};


#endif //D05_PRESIDENTIALPARDONFORM_HPP
