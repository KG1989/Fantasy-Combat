#include "HarryPotter.hpp"

HarryPotter::HarryPotter(std::string name, int armor, int strength)
{
	this->name = name;
	this->strength = 10;
}

HarryPotter::~HarryPotter()
{
}


int HarryPotter::attack()
{
	int hpAtk = 0;
	//Harry Potter attacks on 2d6
	hpAtk = roll(2, 6);

	std::cout << "Harry Potter attacks with " << hpAtk << " damage points. " << std::endl;

	if (hpAtk == 12)
		std::cout << "Harry Potter attacks with max damage! " << std::endl;
	else if (hpAtk < 3)
		std::cout << "It's not very effective. " << std::endl;

	return hpAtk;
}
void HarryPotter::defend(int damageTaken)
{
	//damage = attackers roll - defenders roll - charactor armor
	//defense for harry potter is 2d6
	int defense = 0;
	int damage = 0;

	bool hogwarts = true;


	defense = roll(2, 6);
	std::cout << "Harry Potter defends with " << defense << std::endl;

	damage = damageTaken - defense;

	if (defense > damageTaken)
	{
		damage = 0;
	}
	//if (damageTaken > 0)
	//{
	//armor is 0
	strength -= damage;
	//}
	while (hogwarts)
	{
		if (strength < 0)
		{
			setStrength(20);
		}
		hogwarts = false;
	}
}

void HarryPotter::heal()
{
	strength = strength + 5;

	if (strength > 10)
		setStrength(10);
}