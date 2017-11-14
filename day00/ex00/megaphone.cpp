/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:40:57 by opogiba           #+#    #+#             */
/*   Updated: 2017/10/30 21:41:03 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	int  i;
	int j;

	i = 1;
	j = 0;

	if (argc > 1)
	{
		while (i < argc)
		{
			while (argv[i][j] != '\0')
			{
				if(int(argv[i][j])>= 97 && int(argv[i][j]) <= 122)
					argv[i][j] = char(argv[i][j] - 32);
				std::cout << argv[i][j];
				j++;
			}
			j = 0;
			i++;
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	return (0);
}
