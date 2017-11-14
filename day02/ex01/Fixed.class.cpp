#include "Fixed.class.hpp"

Fixed::Fixed() {
	_fixed_point = 0;
	std::cout <<"Default constructor called\n";

}
Fixed::Fixed(Fixed const &a) {
	std::cout <<"Copy constructor called\n";
	*this = a;
}


Fixed::Fixed(const int a) {
	setRawBits(a << _fractional_bits);
	std::cout <<"Int constructor called\n";
}

Fixed::Fixed(const float a) {
	setRawBits((int)roundf(a*256));
	std::cout <<"Float constructor called\n";
}



Fixed& Fixed::operator=(const Fixed &oper) {
	std::cout <<"Assignation operator called\n";
	if (this == &oper)
		return *this;
	_fixed_point = oper.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os,const Fixed& oper){
	os << oper.toFloat();
	return os;
}


int Fixed::getRawBits() const {
	std::cout <<"getRawBits member function called\n";
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw) {
	_fixed_point = raw;
}
int Fixed::toInt(void) const {
	return (_fixed_point >> _fractional_bits);
}

float Fixed::toFloat() const  {
	return ((float)_fixed_point / 256);
}

Fixed::~Fixed() {
	std::cout <<"Destructor operator called\n";
}

