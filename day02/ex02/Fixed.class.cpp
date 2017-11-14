#include "Fixed.class.hpp"

Fixed::Fixed() {
	_fixed_point = 0;
//	std::cout <<"Default constructor called\n";

}

Fixed::Fixed(Fixed const &a) {
//	std::cout <<"Copy constructor called\n";
	*this = a;
}

Fixed::Fixed(const int a) {
	setRawBits(a << _fractional_bits);
//	std::cout <<"Int constructor called\n";
}

Fixed::Fixed(const float a) {
	setRawBits((int)roundf(a*256));
//	std::cout <<"Float constructor called\n";
}


Fixed& Fixed::operator=(const Fixed &oper) {
//	std::cout <<"Assignation operator called\n";
	if (this == &oper)
		return *this;
	_fixed_point = oper.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &val) const {

	return Fixed(this->toFloat() + val.toFloat());
}
Fixed Fixed::operator-(const Fixed &val) const {

	return Fixed(this->toFloat() - val.toFloat());
}
Fixed Fixed::operator*(const Fixed &val) const {

	return Fixed(this->toFloat() * val.toFloat());
}
Fixed Fixed::operator/(const Fixed &val) const {
	return Fixed(this->toFloat() * val.toFloat());
}

bool Fixed::operator<(const Fixed& val) const {
	if (this->toFloat() < val.toFloat())
		return true;
	return false;
}
bool Fixed::operator<=(const Fixed& val) const {
	if (this->toFloat() <= val.toFloat())
		return true;
	return false;
}

bool Fixed::operator>(const Fixed& val) const {
	if (this->toFloat() > val.toFloat())
		return true;
	return false;
}
bool Fixed::operator>=(const Fixed& val) const {
	if (this->toFloat() >= val.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& val) const {
	if (this->toFloat() == val.toFloat())
		return true;
	return false;
}
bool Fixed::operator!=(const Fixed& val) const {
	if (this->toFloat() != val.toFloat())
		return true;
	return false;
}

Fixed& Fixed::operator++() {
	this->_fixed_point = ++_fixed_point;
	return (*this);
}

Fixed& Fixed::operator--() {
	this->_fixed_point = --_fixed_point;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return temp;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--*this;
	return temp;
}

std::ostream& operator<<(std::ostream& os,const Fixed& oper){
	os << oper.toFloat();
	return os;
}


Fixed& Fixed::min(Fixed& val1, Fixed& val2) {
	if(val1._fixed_point > val2._fixed_point)
		return (val2);
	return (val1);
}

const Fixed& Fixed::min(const Fixed& val1, const Fixed &val2) {
	if(val1._fixed_point > val2._fixed_point)
		return (val2);
	return (val1);
}

Fixed& Fixed::max(Fixed& val1, Fixed& val2) {
	if(val1._fixed_point > val2._fixed_point)
		return (val1);
	return (val2);
}

const Fixed& Fixed::max(const Fixed& val1, const Fixed& val2) {
	if(val1._fixed_point > val2._fixed_point)
		return (val1);
	return (val2);
}





int Fixed::toInt(void) const {
	return (_fixed_point >> _fractional_bits);
}

float Fixed::toFloat() const  {
	return ((float)_fixed_point / 256);
}

int Fixed::getRawBits() const {
//	std::cout <<"getRawBits member function called\n";
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw) {
	_fixed_point = raw;
}

Fixed::~Fixed() {
//	std::cout <<"Destructor operator called\n";
}




//Fixed	 operator+(const Fixed &left, const Fixed &right) {
//	std::cout <<"Plus operator called\n";
//	return Fixed(left.toFloat() + right.toFloat());
//}
