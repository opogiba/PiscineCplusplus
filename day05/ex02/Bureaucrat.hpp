#include "iostream"

#ifndef D05_BUREACRAT_HPP
#define D05_BUREACRAT_HPP

#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	int _grade;
	std::string const _name;


public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat();
	Bureaucrat &	operator=(Bureaucrat const &);
	void			operator+=(int const num);
	void			operator-=(int const num);
	int get_grade() const;
	const std::string &get_name() const;
	void	signForm(Form &);
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

std::ostream &	operator<<(std::ostream &, Bureaucrat const &);


#endif
