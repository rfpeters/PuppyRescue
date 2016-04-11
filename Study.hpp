/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The user finds a key in a desk.  The key is used to
**    unlock the bedroom.
********************************************************************/
#ifndef STUDY_HPP
#define STUDY_HPP

#include "Room.hpp"

class Study: public Room
{
public:
	Study(Inventory*);
	void addRooms(Room*);
	void enterRoom();
	void special();
	Room* action();
};
#endif