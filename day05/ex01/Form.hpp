//
// Created by Oleksiy Pogiba on 11/7/17.
//

#include "iostream"


#ifndef D05_FORM_HPP
#define D05_FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	int const _signed_grade;
	int const _exec_grade;
public:
	Form();
	Form(std::string name, int sign, int exec);
	Form(Form const &);
	~Form();
	Form &	operator=(Form const &);

	void	beSigned(Bureaucrat & src);

	const std::string &get_name() const;

	const int get_signed_grade() const;

	const int get_exec_grade() const;

	bool is_signed() const;

	void set_signed();


	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &);
		~GradeTooLowException() throw();
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &);
		~GradeTooHighException() throw();
		virtual const char* what() const throw();
	};


};

std::ostream &	operator<<(std::ostream & o, Form const & val);

#endif //D05_FORM_HPP
