//
// Created by Oleksiy Pogiba on 11/10/17.
//

#ifndef D08_SPAN_HPP
#define D08_SPAN_HPP

#include "iostream"
#include "vector"

class Span {
private:
    unsigned int   _amount;
    std::vector<int> vec;
public:
    Span();
    Span(unsigned int n);
    Span(const Span & val);
    ~Span();
    Span & operator=(Span const & val);
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();
};


#endif //D08_SPAN_HPP
