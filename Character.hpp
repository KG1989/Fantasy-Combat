#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath> //ceil

class Character
{
protected:
	//protected member variables as stated in project description.
	//these are only the set ones, attack and defense are variable so
	//will leave those out
	std::string name;	
	int armor;
	int strength;
public:
	Character();
	virtual ~Character();

	void setName(std::string);
	std::string getName();
	//virtual functions
	virtual int attack() = 0;
	virtual void defend(int) = 0;
	virtual void heal() = 0;
	//function for getting attack and defense points
	int roll(int, int);
	void setStrength(int);
	int getStrength();
	int getArmor();
	void setArmor(int);
};

#endif