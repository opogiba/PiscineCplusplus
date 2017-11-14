//
// Created by Oleksiy Pogiba on 11/9/17.
//

#ifndef D08_EASYFIND_HPP
#define D08_EASYFIND_HPP

#include "iostream"
#include "map"
#include "vector"
#include "list"


template <typename T>
int easyfind(T val, int a)
{
    typename T::iterator it;
    for (it = val.begin(); it != val.end(); it++)
    {
        if (*it == a)
            return 1;

    }
    throw std::exception();
}

#endif //D08_EASYFIND_HPP
