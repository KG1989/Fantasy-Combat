#include "Barbarian.hpp"

Barbarian::Barbarian(std::string name, int armor, int strength)
{
	this->name = name;
	this->strength = 12;
}

Barbarian::~Barbarian()
{
}

int Barbarian::attack()
{
	 //barbarian attacks on 2d6
	int barbAtk = 0;

	barbAtk = roll(2, 6);

	std::cout << "Barbarian attacks with " << barbAtk << " damage points. " << std::endl;

	if (barbAtk < 3)
		std::cout << "It's not very effective. " << std::endl;
	else if (barbAtk == 12)
		std::cout << "Max damage from Barbarian! " << std::endl;

	return barbAtk;
}
void Barbarian::defend(int damageTaken)
{
	//damage = attackers roll - defenders roll - charactor armor
	//defense for barb is 2d6
	int defense = 0;
	int damage = 0;
	
	defense = roll(2, 6);
	std::cout << "Barbarian defends with " << defense << std::endl;

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

	if (strength < 0)
	{
		setStrength(0);
	}
}

void Barbarian::heal()
{
	strength = strength + 6;

	if (strength > 18)
		setStrength(18);
}
