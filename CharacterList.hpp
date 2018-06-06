#ifndef CHARACTERLIST_HPP
#define CHARACTERLIST_HPP

#include "Character.hpp"

class CharacterList 
{
private:
	struct CharNode 
	{
		CharNode *next;
		//CharNode* prev; dont think I need this because I used singly linked lists
		Character *character;
		CharNode(Character *characterIn, CharNode *nextIn = NULL) {
			character = characterIn;
			next = nextIn;
		}
	};

	CharNode *top; //for stack
	CharNode *head;
	CharNode *tail;

public:
	CharacterList();
	~CharacterList();
	bool isEmptyStack() const;	//is loser stack empty
	bool isEmptyQueue() const; //is lineup queue empty
	//void clear();				//clear all
	void addHead(Character *);		//add to head, used for the loser stack
	void addTail(Character *);		//add to tail, used for the lineup queue
	void removeFront();		//used for removing winning fighter, or losing fighter, from queue and then calling addBack to add to back to fight again, or added to head of stack
	Character* getFront();	//returns character in the front of the list to grab current fighter
	void displayLosers() const;	//used to display the loser stack in the end
	void displayWinners() const; //displays remaining fighters in the winning queue
};

/* for printing losers
CharNode *temp=top;
while(temp!=NULL)
{
cout<<temp->Character->getName() << endl;
temp=temp->next;
}*/

#endif