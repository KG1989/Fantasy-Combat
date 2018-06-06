#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire :
	public Character
{
public:
	Vampire(std::string, int, int);
	~Vampire();
	int attack();
	void defend(int);
	void heal();
};

#endif