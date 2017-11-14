#include <iostream>
#include "easyfind.hpp"

int main() {
    std::vector<int>::iterator it;
    std::vector <int> vecInt(10);
    for(int i=0;i<10;++i)
    {
        vecInt[i]=i;
    }
    for(it=vecInt.begin(); it<vecInt.end(); ++it)
    {
        std::cout<<*it<<std::ends;
    }
    std::cout << std::endl;
    std::cout <<easyfind(vecInt, 3) << std::endl;;

    return 0;
}