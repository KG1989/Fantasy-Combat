#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian :
	public Character
{
private:
	//int strength;
	//int armor;
public:
	Barbarian(std::string,int,int);
	~Barbarian();

	int attack();
	void defend(int);
	void heal();

};

#endif