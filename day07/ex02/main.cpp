#include "Array.hpp"
#include "iostream"

int main()
{
    Array <int>A;
    Array<int>B(10);


    try {
        for (int i = 0; i < 11; i++){
            B[i] = i;
            std::cout << B[i] << " ";
        }
    }
    catch (std::exception e) {
        std::cout << std::endl<< e.what() << std::endl;

    }

    A = B;

    try {
        for (int i = 0; i < 11; i++){
            A[i] = i;
            std::cout << A[i] << " ";
        }
    }
    catch (std::exception e) {
        std::cout << std::endl<< e.what() << std::endl;
    }
    Array<double>C(10);
    try {
        for (int i = 0; i < 11; i++){
            C[i] = i * 1.1;
            std::cout << C[i] << " ";
        }
    }
    catch (std::exception e) {
        std::cout << std::endl<< e.what() << std::endl;
    }



    return (0);
}