#include "Character.hpp"

Character::Character()
{
}


Character::~Character()
{
}

//since some characters have different dice and different dice,
//this function takes account for that and returns the roll(s)
int Character::roll(int numRolls, int sides)
{
	int points = 0;
	for (int i = 0; i < numRolls; i++)
	{
		points += rand() % sides + 1;
	}
	return points;
}

void Character::setName(std::string name)
{
	this->name = name;
}
std::string Character::getName()
{
	return name;
}
void Character::setStrength(int strength)
{
	this->strength = strength;
}
int Character::getStrength()
{
	return strength;
}
int Character::getArmor()
{
	return armor;
}
void Character::setArmor(int armor)
{
	this->armor = armor;
}