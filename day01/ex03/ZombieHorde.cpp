#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {
	n = N - 1;
	if (n < 1)
		n = 0;
	zombies = new Zombie[N];
}

void ZombieHorde::announce() {
	int i;

	i = 0;
	while (i <= n)
	{
		zombies[i].announce();
		i++;
	}

}

ZombieHorde::~ZombieHorde() {
delete [] zombies;
	std::cout << "All zombies dead\n";
}
