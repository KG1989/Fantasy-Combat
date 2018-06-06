#include "Character.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Fight.hpp"
#include "BlueMen.hpp"
#include "CharacterList.hpp"
#include "Util.hpp"

int main()
{

	srand(time(NULL));
	
	Fight go;

	go.play();

	return 0;
}