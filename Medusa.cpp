#include "Medusa.hpp"

Medusa::Medusa(std::string name, int armor, int strength)
{
	this->name = name;
	this->armor = 3;
	this->strength = 8;
}


Medusa::~Medusa()
{
}

int Medusa::attack()
{
	int medAtk = 0;

	medAtk = roll(2, 6);

	std::cout << "Medusa attacks with " << medAtk << " damage points. " << std::endl;

	if (medAtk == 12)
	{
		std::cout << "Medusa attacks with max damage. Glare activated! " << std::endl;
		std::cout << "You stared into her eyes and are killed immediately. " << std::endl;
		//make sure the character really is dead.
		medAtk = 1000;
		return medAtk;
	}
	
	return medAtk;
}
void Medusa::defend(int damageTaken)
{
	//damage = attackers roll - defenders roll - charactor armor
	//defense for medusa is 1d6
	int defense = 0;
	int damage = 0;

	defense = roll(2, 6);
	std::cout << "Medusa defends with " << defense << std::endl;

	damage = damageTaken - defense - armor;

	if (damageTaken - defense - armor < 0)
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

void Medusa::heal()
{
	strength = strength + 4;

	if (strength > 8)
		setStrength(8);
}

