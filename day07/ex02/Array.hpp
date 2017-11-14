//
// Created by Oleksiy Pogiba on 11/9/17.
//

#ifndef DAY07_ARRAY_HPP
#define DAY07_ARRAY_HPP

#include "iostream"

template <class T>
class Array {
private:
    T* _array;
    unsigned int _len;
public:
    Array(){
        _array = new T[0];
        _len = 0;
    };
    Array(unsigned int n) : _len(n){
        _array = new T[n];
    };

    Array(Array & val1){
        *this = val1;
    };

    Array & operator=(Array & val){

        if (this == &val)
            return *this;
        this->_len = val._len;
        if(this->_array)
        {
            delete[]this->_array;
        }
        this->_array = new T[val._len];

        for (unsigned int i = 0; i < val._len; i++) {
            this->_array[i] = val._array[i];
        }
        return *this;

    };
    T &operator[](unsigned int n){
        if (n < this->_len)
            return (this->_array[n]);
        throw std::exception();

    };

    unsigned int size() {return (this->_len);};
    ~Array() {
        if(this->_array)
            delete [] this->_array;
    }
};


#endif //DAY07_ARRAY_HPP
