//
// Created by Oleksiy Pogiba on 11/10/17.
//

#ifndef D08_MUTANTSTACK_HPP
#define D08_MUTANTSTACK_HPP

#include "iostream"
#include "stack"
#include "set"

template <class T>

class MutantStack : public std::stack<T> {
private:
public:
 
    typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack() {}
    MutantStack(MutantStack const & src) : std::stack<T>(src){ }
    ~MutantStack() { }
    using 	std::stack<T>::operator=;

    iterator	begin() { return std::stack<T>::c.begin(); }
    iterator	end() { return std::stack<T>::c.end(); }


};


#endif //D08_MUTANTSTACK_HPP
