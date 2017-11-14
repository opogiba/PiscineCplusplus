#include "Fixed.class.hpp"

Fixed::Fixed() {
	_fixed_point = 0;
	std::cout <<"Default constructor called\n";

}
Fixed::Fixed(Fixed &a) {
	std::cout <<"Copy constructor called\n";
	*this = a;
}

Fixed::~Fixed() {
	std::cout <<"Destructor operator called\n";
}

Fixed& Fixed::operator=(const Fixed &oper) {
	std::cout <<"Assignation operator called\n";
	if (this == &oper)
		return *this;
	_fixed_point = oper.getRawBits();
	return (*this);
}


int Fixed::getRawBits() const {
	std::cout <<"getRawBits member function called\n";
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw) {
	_fixed_point = raw;
}
