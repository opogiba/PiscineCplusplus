// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/11 15:34:48 by nfruneau          #+#    #+#             //
//   Updated: 2015/04/11 15:34:49 by nfruneau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	_tabm = new AMateria*[4];
	
	for (int i = 0; i < 4; ++i)
	{
		_tabm[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const & cpy)
{
	*this = cpy;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	_tabm = rhs._tabm;
	return (*this);
}

void 		MateriaSource::learnMateria(AMateria* m)
{
	int	check;

	check = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (check == 0 && _tabm[i] == NULL)
		{
			_tabm[i] = m;
			check++;
		}
	}
	if (check == 0)
		std::cout << "materia source memory full." << std::endl;
}

AMateria* 	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_tabm[i] != NULL)
		{
			if (_tabm[i]->getType() == type)
			{
				AMateria * cpy;
				cpy = _tabm[i]->clone();
				return (cpy);
			}
		}
	}
	std::cout << "materia source not found." << std::endl;
	return (NULL);
}
