/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: There is a lost dog in a house.  You need to find 
**    treats and a leash to rescue the dog.  The room the dog is in 
**    is locked, you need to find the key.
********************************************************************/
#include "Hallway.hpp"
#include "Study.hpp"
#include "Library.hpp"
#include "Bedroom.hpp"
#include "Kitchen.hpp"

int main()
{
	/*Create Rooms and Inventory*/
	Inventory* bag = new Inventory;
	Hallway* hallway = new Hallway(bag);
	Study* study = new Study(bag);
	Library* library = new Library(bag);
	Bedroom* bedroom = new Bedroom(bag);
	Kitchen* kitchen = new Kitchen(bag);
	Room* currentRoom = hallway;

	/*Empty Inventory*/
	bag->dog = false;
	bag->key = false;
	bag->leash = false;
	bag->treat = false;
	
	/*Connect Rooms*/
	hallway->addRooms(library, bedroom, kitchen, study);
	study->addRooms(hallway);
	library->addRooms(hallway);
	bedroom->addRooms(hallway);
	kitchen->addRooms(hallway);

	/*Loop until dog is rescued*/
	do
	{
		std::cout << currentRoom->getName() << std::endl;

		if (currentRoom->getName().compare("Hallway") == 0)
		{
			hallway->enterRoom();
			hallway->special();
			currentRoom = hallway->action();
		}
		else if (currentRoom->getName().compare("Study") == 0)
		{
			study->enterRoom();
			study->special();
			currentRoom = study->action();
		}
		else if (currentRoom->getName().compare("Library") == 0)
		{
			library->enterRoom();
			library->special();
			currentRoom = library->action();
		}
		else if (currentRoom->getName().compare("Kitchen") == 0)
		{
			kitchen->enterRoom();
			kitchen->special();
			currentRoom = kitchen->action();
		}
		else if (currentRoom->getName().compare("Bedroom") == 0)
		{
			bedroom->enterRoom();
			bedroom->special();
			currentRoom = bedroom->action();
		}

		std::cout << std::endl;
	} while (bag->dog == false);
	/*End loop*/


	if (bag->dog = true)
	{
		std::cout << "Congradulations.  You saved the dog." << std::endl;
	}

	/*Delete Rooms and Inventory*/
	delete hallway;
	delete study;
	delete library;
	delete bedroom;
	delete kitchen;
	delete bag;
	
	return 0;
}