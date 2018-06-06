#include "Fight.hpp"

Fight::Fight()
{
	fighter1 = NULL;
	fighter2 = NULL;
}

Fight::~Fight()
{
	//delete fighter1;
	//delete fighter2;
}

void Fight::createLineup()
{
	int player1Sel = 0;
	int player2Sel = 0;
	int numFighters1 = 0;
	int numFighters2 = 0;
	std::string input;
	std::string name;

	// I should have made a function for this
	//basically just the intro
	cout << "To begin the game, each player will pick one fighter. Each fighter is shown below with a list of their attributes. " << endl;
	cout << endl;
	cout << "*****************************************************************************************************************" << endl;
	cout << "	Fighters: " << endl;
	cout << "	Harry Potter: He's a wizard!!  " << endl
		<< "	Attack: 2d6 " << endl
		<< "	Defense: 2d6 " << endl
		<< "	Armor: 0 " << endl
		<< "	Life Points: 10 " << endl
		<< "	Special Skill: Hogwarts (obviously). When Harry dies, he comes back to life with 20 life points. " << endl;

	cout << "	Vampire: Suave, debonair, but vicious and surprisingly resilient.  " << endl
		<< "	Attack: 1d12 " << endl
		<< "	Defense: 1d6 " << endl
		<< "	Armor: 1 " << endl
		<< "	Life Points: 18 " << endl
		<< "	Special Skill: Charm. 50% chance to charm the enemy into not attacking " << endl;

	cout << "	Medusa: Character out of Greek mythology with snakes for hair and a killer stare. " << endl
		<< "	Attack: 2d6 " << endl
		<< "	Defense: 1d6 " << endl
		<< "	Armor: 3 " << endl
		<< "	Life Points: 8 " << endl
		<< "	Special Skill: Glare. Medusa has a chance to kill you instantly. " << endl;

	cout << "	Barbarian: Think Conan or Hercules from the movies.Big sword, big muscles, bare torso. " << endl
		<< "	Attack: 2d6 " << endl
		<< "	Defense: 2d6 " << endl
		<< "	Armor: 0 " << endl
		<< "	Life Points: 12 " << endl
		<< "	Special Skill: None " << endl;

	cout << "	Blue Men: Large group of tiny blue things. " << endl
		<< "	Attack: 2d10 " << endl
		<< "	Defense: 3d6 " << endl
		<< "	Armor: 3 " << endl
		<< "	Life Points: 12 " << endl
		<< "	Special Skill: Mob. Blue Men are actually a swarm of small individuals. " << endl
		<< "	For every 4 points of damage, they lose one defense die. " << endl
		<< "	For example, if they have strength 8, they would have 2d6 for defense." << endl;

	cout << endl;
	cout << "*****************************************************************************************************************" << endl;

	//list of characters
	cout << "Time to choose characters! player 1 choose first. " << endl;
	cout << "1: Barbarian. " << endl
		<< "2: Vampire. " << endl
		<< "3: Medusa. " << endl
		<< "4: Harry Potter. " << endl
		<< "5: Blue Men. " << endl;

	//enter number of fighters for player 1 team
	cout << "How many fighters for team1? no more than 25, let's be real here. " << endl;
	numFighters1 = getInt(input, 0, 25);
	cout << "Player 1 select fighters based on the numeric choices shown. " << endl;
	//for loop to select fighters
	for (int i = 0; i < numFighters1; i++)
	{
		player1Sel = getInt(input, 1, 5);

		//based on player selection, dynamically allocate memory for a new character object
		switch (player1Sel)
		{
		case 1:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team1.addTail(new Barbarian(name, 0, 12));
			cout << "Barbarian chosen! " << endl;
			break;
		}
		case 2:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team1.addTail(new Vampire(name, 1, 18));
			cout << "Vampire chosen! " << endl;
			break;
		}
		case 3:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team1.addTail(new Medusa(name, 3, 8));
			cout << "Medusa chosen! " << endl;
			break;
		}
		case 4:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team1.addTail(new HarryPotter(name, 0, 12));
			cout << "Harry Potter chosen! " << endl;
			break;
		}
		case 5:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team1.addTail(new BlueMen(name, 3, 12));
			cout << "Blue Men chosen! " << endl;
			break;
		}
		default:
			break;
		}

		//this just tells the person to keep choosing until their last selection
		//so they know what they are doing
		if (i < numFighters1 - 1)
		{
			cout << "Choose again. " << endl;
		}
	}
	cout << endl;
	Team1.displayWinners();
	//tell team 2 to choose and re-display the list
	cout << "Now team 2 chooses. " << endl;
	cout << "Here are the choices again. " << endl;
	cout << "1: Barbarian. " << endl
		<< "2: Vampire. " << endl
		<< "3: Medusa. " << endl
		<< "4: Harry Potter. " << endl
		<< "5: Blue Men. " << endl;
	//enter number of fighters for team 2
	cout << "How many fighters for team2? no more than 25, let's be real here. " << endl;
	numFighters2 = getInt(input, 0, 25);
	cout << "Player 2 select fighters based on the numeric choices shown. " << endl;

	//for loop for choosing fighters for team 2
	for (int i = 0; i < numFighters2; i++)
	{
		player2Sel = getInt(input, 1, 5);

		//based on player selection, dynamically allocate memory for a new character object
		switch (player2Sel)
		{
		case 1:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team2.addTail(new Barbarian(name, 0, 12));
			cout << "Barbarian chosen! " << endl;
			break;
		}
		case 2:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team2.addTail(new Vampire(name, 1, 18));
			cout << "Vampire chosen! " << endl;
			break;
		}
		case 3:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team2.addTail(new Medusa(name, 3, 8));
			cout << "Medusa chosen! " << endl;
			break;
		}
		case 4:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team2.addTail(new HarryPotter(name, 0, 12));
			cout << "Harry Potter chosen! " << endl;
			break;
		}
		case 5:
		{
			cout << "enter nickname for fighter. " << endl;
			getline(cin, name);

			Team2.addTail(new BlueMen(name, 3, 12));
			cout << "Blue Men chosen! " << endl;
			break;
		}
		default:
			break;
		}

		//this just tells the person to keep choosing until their last selection
		//so they know what they are doing
		if (i < numFighters2 - 1)
		{
			cout << "Choose again. " << endl;
		}
	} //end for loop choosing fighters

}


void Fight::play()
{
	std::vector<std::string> vec;

	int roundCount = 1;
	int selection = 0;
	//scoring is based on number of rounds won. whoever has won the most rounds wins.
	//each team gets a point after winning a round.
	int team1Score = 0;
	int team2Score = 0;
	int goFirst = 0;

	createLineup();

	//set the fighters to the front of the list so the first characters fight each other
	fighter1 = Team1.getFront();
	fighter2 = Team2.getFront();

	cout << fighter1->getName() << endl;
	cout << fighter2->getName() << endl;

	//loops until head points to NULL for one of the teams which means
	//the queue is empty
	while (!Team1.isEmptyQueue() && !Team2.isEmptyQueue())
	{
		cout << "Round " << roundCount << ": " << endl;
		cout << fighter1->getName() << " vs " << fighter2->getName() << endl;

		//50/50 chance to see who goes first
		goFirst = rand() % 2 + 1;

		switch (goFirst)
		{
		case 1:
			//taken from project3, loops until a fighter is dead
			while (fighter1->getStrength() && fighter2->getStrength())
			{
				fighter2->defend(fighter1->attack());
				/*
				if (fighter2->getStrength() == 0)
				{
					cout << fighter2->getName() << " has been killed. fighter 1 wins this round! " << endl;
					break;
				}
				*/
				fighter1->defend(fighter2->attack());
				/*
				if (fighter1->getStrength() == 0)
				{
					cout << fighter1->getName() << " has been killed. fighter 2 wins this round! " << endl;
					break;
				}
				*/
			} //end round fight loop
			break;
		case 2:
			while (fighter1->getStrength() && fighter2->getStrength())
			{
				fighter1->defend(fighter2->attack());
				fighter2->defend(fighter1->attack());
			}
			break;
		} //end switch

		//fighters have done their fighting for the round

		//if fighter1 from team1 has been killed
		if (fighter1->getStrength() == 0)
		{
			cout << fighter1->getName() << " has been killed. fighter 2 wins this round! " << endl;
			team2Score++;

			//remove fighter 1 from queue
			Team1.removeFront();
			//add to loser stack
			loserStack.addHead(fighter1);

			//move fighter 2 to end of queue and heal
			fighter2->heal();
			Team2.removeFront();
			Team2.addTail(fighter2);

			//bring new fighters to the front
			fighter1 = Team1.getFront();
			fighter2 = Team2.getFront();
		}
		else
		{
			cout << fighter2->getName() << " has been killed. fighter 1 wins this round! " << endl;
			team1Score++;

			//remove fighter 2 from queue
			Team2.removeFront();
			//add to loser stack
			loserStack.addHead(fighter2);

			//move fighter 2 to end of queue and heal
			fighter1->heal();
			Team1.removeFront();
			Team1.addTail(fighter1);

			//bring new fighters to the front
			fighter1 = Team1.getFront();
			fighter2 = Team2.getFront();
		}

		roundCount++;
	}//end game while loop

	cout << roundCount << endl;
	cout << team1Score << endl;
	cout << team2Score << endl;

	cout << "dead fighters. " << endl;
	loserStack.displayLosers();
	cout << "survivors from team1. " << endl;
	Team1.displayWinners();
	cout << "survivors from team2. " << endl;
	Team2.displayWinners();
}

/*
void Fight::play()
{
	int roundCount = 1;
	std::vector<std::string> vec;
	int selection = 0;

	cout << "Welcome to the utltimate fantasy combat game! " << endl;
	cout << "Please select 0 to view the menu, 1 to start the game, or 2 to quit right away! " << endl;

	while (selection != 2)
	{
		menu(selection, vec, "Enter 1 to start the game", "Enter 2 to quit");

		if (selection == 1)
		{
			createLineup();

			//both need to be logic 1 for loop to continue, will end if one is 0 (dead)
			while (player1->getStrength() && player2->getStrength())
			{
				player2->defend(player1->attack());

				if (player2->getStrength() == 0)
				{
					cout << player2->getName() << " has been killed. Player 1 wins! " << endl;
					break;
				}

				player1->defend(player2->attack());

				if (player1->getStrength() == 0)
				{
					cout << player1->getName() << " has been killed. Player 2 wins! " << endl;
					break;
				}

				cout << "Player 1 strength after round " << roundCount << ": " << player1->getStrength() << endl;
				cout << "Player 2 strength after round " << roundCount << ": " << player2->getStrength() << endl;

				roundCount++;
			}
			cout << "Number of rounds: " << roundCount << endl;

			cout << "battle again? Enter 0 to see the menu, 1 to start the game or 2 to quit" << endl;
			menu(selection, vec, "Enter 1 to start the game", "Enter 2 to quit");
		}
	}
	
}
*/