/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The main hub connecting all the rooms.  The user can
**    turn the lights on and choose which room to visit.
********************************************************************/
#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "Room.hpp"

class Hallway: public Room
{
private:
	bool lightsOn;
public:
	Hallway(Inventory*);
	void addRooms(Room*, Room*, Room*, Room*);
	void enterRoom();
	void special();
	Room* action();
};
#endif