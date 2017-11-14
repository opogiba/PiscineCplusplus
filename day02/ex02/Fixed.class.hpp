//
// Created by Oleksiy Pogiba on 11/1/17.
//

#ifndef DAY02_FIXEDCLASS_HPP
#define DAY02_FIXEDCLASS_HPP

#include <iostream>
#include <cmath>


class Fixed {
private:
	int _fixed_point;
	static const int _fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &a);
	Fixed(const int a);
	Fixed(const float a);
	~Fixed();
	int getRawBits (void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed& oper);
	float toFloat(void) const ;
	int toInt(void) const ;
	Fixed operator+(const Fixed &val) const;
	Fixed operator-(const Fixed &val) const;
	Fixed operator*(const Fixed &val) const;
	Fixed operator/(const Fixed &val) const;
	bool operator<(const Fixed& val) const;
	bool operator<=(const Fixed& val) const;
	bool operator>=(const Fixed& val) const;
	bool operator>(const Fixed& val) const;
	bool operator!=(const Fixed& val) const;
	bool operator==(const Fixed& val) const;


	static Fixed& min(Fixed& val1, Fixed& val2);
	static const Fixed& min(const Fixed &val1, const Fixed &val2);
	static Fixed& max(Fixed& val1, Fixed& val2);
	static const Fixed& max(const Fixed& val1, const Fixed& val2);

	Fixed&operator++();
	Fixed operator--(int);
	Fixed operator++(int);
	Fixed& operator--();



};
//Fixed operator+(const Fixed &left, const Fixed &right);


std::ostream& operator<<(std::ostream& os,const Fixed& oper);


#endif
