#pragma once
#include "Character.hpp"
class HarryPotter :
	public Character
{
private:
	
public:
	HarryPotter(std::string, int, int);
	~HarryPotter();
	int attack();
	void defend(int);
	void heal();

};

