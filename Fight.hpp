#ifndef FIGHT_HPP
#define FIGHT_HPP

#include "Character.hpp"
#include "Util.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "CharacterList.hpp"

using std::cout;
using std::endl;

class Fight
{
private:
	Character *fighter1;
	Character *fighter2;
	CharacterList Team1;
	CharacterList Team2;
	CharacterList loserStack;
public:
	Fight();
	~Fight();
	
	//setup and all that
	void createLineup();
	void play();
};

#endif