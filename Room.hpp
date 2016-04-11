/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: Abstract class for the rooms.  Has pointers to 
**    connecting rooms, a pointer to the Inventory, and the
**    room name.  There is a function for getting the room name.  
**    There are virual functions for entering the room and special
**    task.
********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP

#include "Inventory.hpp"
#include <iostream>
#include <string>
#include <limits>

class Room
{
protected:
	Room* r1;
	Room* r2;
	Room* r3;
	Room* r4;
	Inventory* bag;
	std::string name;
public:
	/*******************************************************************
	** Descritpion: Get the room name.
	** Return: name
	*******************************************************************/
	std::string getName()
	{
		return name;
	}
	/*Virtual Functions*/
	virtual void enterRoom() = 0;
	virtual void special() = 0;
	virtual Room* action() = 0;
};
#endif