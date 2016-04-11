/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The dog is located in the bedroom.  You need the key
**    to enter the room, and treats and the leash to rescue the dog.
********************************************************************/
#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Room.hpp"

class Bedroom: public Room
{
public:
	Bedroom(Inventory*);
	void addRooms(Room*);
	void enterRoom();
	void special();
	Room* action();
};
#endif