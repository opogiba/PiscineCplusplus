
#include "iostream"

template <typename T1, typename T2>
void iter (T1 *val1, int len, T2 (*func)(T1))
{
    for (int i = 0; i < len; ++i) {
        func(val1[i]);
    }

}

int mult(int a)
{
    a = a * 2;
    std::cout << a << " ";
    return a;
}

double mult(double a)
{
    a = a * 2;
    std::cout << a << " ";
    return (a);

}

int div(double a)
{
    a = a / 2;
    std::cout << static_cast<int>(a) << " ";
    return static_cast<int>(a);
}

double div(int a)
{
    a = a / 2;
    std::cout << static_cast<double>(a) << " ";
    return (static_cast<double>(a));

}

int main( void ) {

    int a[] = {1,2,3,4,5};
    double b[] = {1.1,2.2,3.3,4.4,5.5};

    iter(a, 5, static_cast<int (*)(int)>(mult));
    std::cout << std::endl;
    iter(b, 5, static_cast<double (*)(double)>(mult));
    std::cout << std::endl;






    iter(a, 5, static_cast<double (*)(int)>(div));
    std::cout << std::endl;
    iter(b, 5, static_cast<int (*)(double)>(div));
    std::cout << std::endl;
    return 0;
}