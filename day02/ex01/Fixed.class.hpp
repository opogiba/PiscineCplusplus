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



};

std::ostream& operator<<(std::ostream& os,const Fixed& oper);


#endif //DAY02_FIXEDCLASS_HPP
