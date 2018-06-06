#include "Vampire.hpp"

Vampire::Vampire(std::string name, int armor, int strength)
{
	this->name = name;
	this->strength = 18;
	this->armor = 1;
}

Vampire::~Vampire()
{
}
int Vampire::attack()
{
	int vampAtk = 0;

	vampAtk = roll(1, 12);

	std::cout << "Vampire attacks with " << vampAtk << " damage points. " << std::endl;

	if (vampAtk == 12)
		std::cout << "Vampire attacks with max damage! " << std::endl;
	else if (vampAtk < 3)
		std::cout << "It's not very effective. " << std::endl;

	return vampAtk;
}
void Vampire::defend(int damageTaken)
{
	//damage = attackers roll - defenders roll - charactor armor
	//defense for vampire is 1d6
	int defense = 0;
	int damage = 0;
	int charm = 0;

	defense = roll(2, 6);
	std::cout << "Vampire defends with " << defense << std::endl;

	//random numbers from 1 to 2
	charm = (rand() % 2) + 1;

	damage = damageTaken - defense - armor;

	if (damageTaken - defense - armor < 0)
	{
		damage = 0;
	}

	if (charm == 1)
	{
		std::cout << "Charm activated! No damage taken. " << std::endl;
		damage = 0;
		strength -= damage;
	}
	else
	{
		strength -= damage;
	}

	if (strength < 0)
	{
		setStrength(0);
	}
}

//adds half their strength back to them
//if ends up greater than starting amount, set to max.
void Vampire::heal()
{
	strength = strength + 9;

	if (strength > 18)
		setStrength(18);
}
