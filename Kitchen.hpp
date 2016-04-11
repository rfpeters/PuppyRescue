/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The user finds treats in the pantry.  The treates are
**    needed to rescue the dog.
********************************************************************/
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Room.hpp"

class Kitchen: public Room
{
public:
	Kitchen(Inventory*);
	void addRooms(Room*);
	void enterRoom();
	void special();
	Room* action();
};
#endif