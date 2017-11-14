//
// Created by Oleksiy Pogiba on 11/7/17.
//

#ifndef D05_ROBOTOMYREQUESTFORM_HPP
#define D05_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	void execute(Bureaucrat const & executor) const;
	~RobotomyRequestForm();
	const int get_signed_grade() const;
};


#endif //D05_ROBOTOMYREQUESTFORM_HPP
