//
// Created by Oleksiy Pogiba on 11/1/17.
//

#ifndef DAY02_FIXEDCLASS_HPP
#define DAY02_FIXEDCLASS_HPP

#include <iostream>


class Fixed {
private:
	int _fixed_point;
	static const int _fractional_bits = 8;
public:
	Fixed();
	Fixed(Fixed &a);
	~Fixed();
	int getRawBits (void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed& oper);



};


#endif //DAY02_FIXEDCLASS_HPP
