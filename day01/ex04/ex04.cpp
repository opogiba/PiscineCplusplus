#include <iostream>
int main () {
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;
	std::cout << ptr << " " << *ptr << " " << ref << " " << &ref;
	return 0;
}


