#pragma once
#include "Character.hpp"
class Medusa :
	public Character
{
public:
	Medusa(std::string, int, int);
	~Medusa();	
	int attack();
	void defend(int);
	void heal();


};

