//
// Created by Oleksiy Pogiba on 11/10/17.
//

#include "Span.hpp"

Span::Span() {
    _amount = 0;
    vec.reserve(0);

}
Span::Span(unsigned int n) {
    _amount = n;
    vec.reserve(_amount);
}



Span::Span( const Span &val) {
    *this = val;
}

Span & Span::operator=(Span const & val)
{
    if(this == &val)
        return *this;


    this->vec.clear();
    this->vec = val.vec;
    this->_amount = val._amount;
    return *this;

}

void Span::addNumber(int n) {
    if (this->vec.size() < _amount)
        vec.push_back(n);
    else
        throw std::exception();
}

int Span::shortestSpan() {
    if(_amount <= 1)
        throw std::exception();
    std::vector<int> copy = this->vec;
    std::sort (copy.begin(), copy.end());
    return ((copy[1]) - copy[0]);


}

int Span::longestSpan() {
    if(_amount <= 1)
        throw std::exception();
    std::vector<int> copy = this->vec;
    std::sort (copy.begin(), copy.end());
    return (*(copy.end() - 1)  - copy[0]);


}

Span::~Span() {
    this->vec.clear();
}