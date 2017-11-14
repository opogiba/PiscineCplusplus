#include "ZombieHorde.hpp"

int main()
{
	srand(clock());
	ZombieHorde *p = new ZombieHorde(5);
	p->announce();
	return (0);
}