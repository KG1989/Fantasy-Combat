#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"
class BlueMen :
	public Character
{
public:
	BlueMen(std::string, int, int);
	~BlueMen();
	int attack();
	void defend(int);
	void heal();
};

#endif