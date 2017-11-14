// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 13:25:44 by nfruneau          #+#    #+#             //
//   Updated: 2015/01/09 13:25:44 by nfruneau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"
#include <iostream>

Victim::Victim(std::string name) {

	_name = name;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::Victim(Victim & src) {

	*this = src;
	std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
}

Victim::~Victim() {

	std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;	
}

Victim &	Victim::operator=(Victim & rhs) {

	this->_name = rhs._name;
	return *this;
}

std::string	Victim::getName() const {

	return (this->_name);
}

std::ostream &	operator<<(std::ostream & o, Victim const & rhs) {

	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;	
	return o;
}

void	Victim::getPolymorphed() const {

	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}