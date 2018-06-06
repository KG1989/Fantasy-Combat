#include "BlueMen.hpp"

BlueMen::BlueMen(std::string name, int armor, int strength)
{
	this->name = name;
	this->armor = 3;
	this->strength = 12;
}

BlueMen::~BlueMen()
{
}

int BlueMen::attack()
{
	int blueAtk = 0;

	blueAtk = roll(2, 10);

	std::cout << "Blue men attack with " << blueAtk << " damage points. " << std::endl;

	if (blueAtk == 20)
		std::cout << "Nue men attack with max damage! " << std::endl;
	else if (blueAtk < 3)
		std::cout << "It's not very effective. " << std::endl;

	return blueAtk;
}
void BlueMen::defend(int damageTaken)
{
	int mob = 0;
	int defense = 0;
	int damage = 0;
	//every 4 points lost, defense is different.
	//using integer division with ceiling function.
	//12/4 = 3, plug into defense eqution and have 3d6
	//11/4 = 3, 10/4 = 3, 9/4 = 3
	mob = ceil(strength / 4);

	defense = roll(mob, 6);

	//damage = attackers roll - defenders roll - charactor armor

	std::cout << "Blue Men defend with " << defense << std::endl;

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

void BlueMen::heal()
{
	strength = strength + 6;

	if (strength > 12)
		setStrength(12);
}