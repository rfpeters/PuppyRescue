/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The user finds a leash on a table.  The least is
**    needed to rescue the dog.
********************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Room.hpp"

class Library: public Room
{
public:
	Library(Inventory*);
	void addRooms(Room*);
	void enterRoom();
	void special();
	Room* action();
};
#endif