
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("Bureaucrat-default"){

	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)  {

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}


Bureaucrat::Bureaucrat(Bureaucrat const & val) : _name(val._name){

	*this = val;
}

Bureaucrat::~Bureaucrat() {};

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & val)  {


	this->_grade = val._grade;
	return *this;
}

void	Bureaucrat::operator-=(int const num) {

	if ((this->_grade + num) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += num;
}

void	Bureaucrat::operator+=(int const num) {

	if ((this->_grade - num) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= num;
}

int Bureaucrat::get_grade() const {
	return _grade;
}

void	Bureaucrat::signForm(Form & val) {

	if (this->_grade <= val.get_signed_grade() && val.is_signed() == false) {
		std::cout << this->_name << " signs " << val.get_name() << std::endl;
		val.set_signed();
	}
	else if (this->_grade > val.get_signed_grade()) {
		std::cout << this->_name << " cannot sign " << val.get_name() << " because his grade is too low." << std::endl;
	}
	else if (val.is_signed() == true) {
		std::cout << this->_name << " cannot sign " << val.get_name() << " because the form is signed." << std::endl;
	}
}

const std::string &Bureaucrat::get_name() const {
	return _name;
}








Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & val) {
	*this = val;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}



const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat grade too high");
}












Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & val) {
	*this = val;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}



const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat grade too low");
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & val) {

	o << val.get_name() << ", bureaucrat grade " << val.get_grade() << "." << std::endl;
	return o;
}
