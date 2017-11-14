//
// Created by Oleksiy Pogiba on 11/5/17.
//

#ifndef RUSH00_MEDICAL_HELP_HPP
#define RUSH00_MEDICAL_HELP_HPP

#include "Entry.hpp"

class Medical_help : public Entry {
protected:
	Medical_help();
public:
	Medical_help(int x, int y);
	Medical_help (const Medical_help &val);
	~Medical_help();
	void move (int count);
};


#endif //RUSH00_MEDICAL_HELP_HPP
