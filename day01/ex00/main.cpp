#include "Pony.hpp"

void ponyOnTheHeap()
{
	Pony *Heap = new Pony ("Barbara", "Anna", 1);
	std::cout << "Pony created in the heap\n";
	std::cout << "If don't call delete. We loose Barbara forever\n";
	delete(Heap);
	std::cout << "Destructor called when we use delete\n\n";

}
void ponyOnTheStack()
{
	Pony Stack ("Simba", "Alex", 2);
	std::cout << "Pony created in the stack\n";
	std::cout << "Destructor called automatically\n";
}
int main()
{
	ponyOnTheHeap();
	ponyOnTheStack();
	return 0;
}