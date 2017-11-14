#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {

	srand(clock());

	Intern a;

	a.makeForm("robotomy request", "dkmasda");
	Intern b;
	b.makeForm("shrubbery creation", "dkmasda");
	Intern c;
	c.makeForm("presidential pardon", "dkmasda");

	return 0;
}
