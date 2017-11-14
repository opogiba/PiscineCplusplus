#include <iostream>
#include "iomanip"

template <typename T>
void swap (T & val1, T & val2)
{
    T tmp;

    tmp = val1;
    val1 = val2;
    val2 = tmp;
}

template <typename T>
T min (const T & val1,const  T & val2) {
    if(val1 < val2)
        return(val1);
    return (val2);
}

template <typename T>
T max (const T & val1, const T & val2) {
    if(val1 > val2)
        return(val1);
    return (val2);
}


int main( void ) {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( 2, 3 ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}