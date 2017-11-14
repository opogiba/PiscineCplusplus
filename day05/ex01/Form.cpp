//
// Created by Oleksiy Pogiba on 11/7/17.
//

#include "Form.hpp"


Form::Form() : _name("Form-Default"),  _signed(false), _signed_grade(1), _exec_grade(10) {}

Form::Form(std::string name, int sign, int exec): _name(name), _signed_grade(sign), _exec_grade(exec) {

	if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
	else if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else
		this->_signed = false;
}

Form::Form(Form const & val): _name(val._name), _signed_grade(val._signed_grade), _exec_grade(val._exec_grade) {

	*this = val;
}

Form &	Form::operator=(Form const & val) {

	this->_signed = val._signed;
	return *this;
}

void	Form::beSigned(Bureaucrat & val) {
	if (val.get_grade() > this->_signed_grade)
	{
		throw Form::GradeTooLowException();
	}
	else if (this->_signed == false){
		std::cout << val.get_name() << " signs Form : " << this->_name << " with " << val.get_grade()<< std::endl;
		this->_signed = true;
	}
	else if (this->_signed == true)
		std::cout << val.get_name() << " cannot sign Form :  " << this->_name << " because the form is signed." << std::endl;
}
std::ostream &	operator<<(std::ostream & o, Form const & val) {

	o << val.get_name() << "- Form Name; " << val.get_signed_grade() << " - Signed grade" << val.get_exec_grade() << " - Signed grade" << val.is_signed() << " - Status" << std::endl;
	return o;
}


Form::~Form() {}


const std::string &Form::get_name() const {
	return _name;
}

const int Form::get_signed_grade() const {
	return _signed_grade;
}

const int Form::get_exec_grade() const {
	return _exec_grade;
}

bool Form::is_signed() const {
	return _signed;
}

void Form::set_signed() {
	_signed = true;
}


Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src) {
	*this = src;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}



const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & src) {
	*this = src;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {}


const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}
