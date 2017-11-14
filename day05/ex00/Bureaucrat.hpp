#include "iostream"

#ifndef D05_BUREACRAT_HPP
#define D05_BUREACRAT_HPP


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
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &);
		~GradeTooLowException() throw();
		GradeTooLowException &		operator=(GradeTooLowException const &);
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &);
		~GradeTooHighException() throw();
		GradeTooHighException &		operator=(GradeTooHighException const &);
		virtual const char* what() const throw();
	};



};

std::ostream &	operator<<(std::ostream &, Bureaucrat const &);


#endif
