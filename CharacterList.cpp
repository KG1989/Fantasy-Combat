#include "CharacterList.hpp"

CharacterList::CharacterList()
{
	top = NULL;
	head = NULL;
	tail = NULL;
}

//used from the text
CharacterList::~CharacterList()
{
	CharNode *garbage = head;

	while (garbage != NULL)
	{
		head = head->next;
		garbage->next = NULL;
		delete garbage->character;
		delete garbage;
		garbage = head;
	}

	while (top != NULL)
	{
		CharNode *temp = top;
		top = top->next;
		temp->next = NULL;
		delete temp->character;
		delete temp;
	}
}

bool CharacterList::isEmptyStack() const
{
	if (top == NULL)
	{
		std::cout << "There are no values in the stack. " << std::endl;
		return true;
	}
	else
	{
		std::cout << "We got some values! " << std::endl;
		return false;
	}

}

bool CharacterList::isEmptyQueue() const
{
	if (head == NULL)
	{
		//std::cout << "There are no values in the queue" << std::endl << std::endl;
		return true;
	}
	else
	{
		//std::cout << "We got some values! " << std::endl;
		return false;
	}
}

//add to head, used for the loser stack
void CharacterList::addHead(Character *fighter)
{
	top = new CharNode(fighter, top);
}

//basically an enqueue function
void CharacterList::addTail(Character *fighter)
{
	CharNode *temp = new CharNode(fighter);

	if (isEmptyQueue())
	{
		//empty list so head is the new node
		//one element now so tail and head point to the same thing
		head = temp;
		tail = temp;
	}
	else
	{
		//new node where current tail's next pointer points to 
		tail->next = temp;
		tail = temp;
	}
}

//basically a dequeue function
void CharacterList::removeFront()
{
	//empty list
	if (head != NULL)
	{
		CharNode *temp = head;
		head = head->next;
		delete temp;
		//if head is deleted and no more nodes left, dont leave tail hangin
		if (head == NULL)
		{
			tail = NULL;
		}
	}
	else
	{
		std::cout << "Queue is empty. " << std::endl;
	}
}

Character* CharacterList::getFront()
{
	if (head == NULL)
	{
		std::cout << "The queue is empty. " << std::endl;
		return NULL;
	}
	else
	{
		return head->character;
	}
}

void CharacterList::displayLosers() const
{
	CharNode *temp = top;

	while (temp != NULL)
	{
		std::cout << temp->character->getName() << std::endl;
		temp = temp->next;
	}
}

void CharacterList::displayWinners() const
{
	CharNode *temp = head;

	while (temp != NULL)
	{
		std::cout << temp->character->getName() << std::endl;
		//next is set to point to NULL at the tail so this should keep going until the last node is reached
		temp = temp->next;
	}
}
