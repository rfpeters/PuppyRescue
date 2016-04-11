/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The main hub connecting all the rooms.  The user can
**    turn the lights on and choose which room to visit.
********************************************************************/
#include "Hallway.hpp"

/********************************************************************
** Description: Constructor, sets name, lights off, and pointer
**    to inventory.
** Param b: Pointer to Inventory
********************************************************************/
Hallway::Hallway(Inventory* b)
{
	lightsOn = false;
	name = "Hallway";
	bag = b;
}

/********************************************************************
** Description: Instantiates links to connecting rooms.
** Param library: Pointer to Library
** Param bedroom: Pointer to Bedroom
** Param kitchen: Pointer to Kitchen
** Param study: Pointer to Study
********************************************************************/
void Hallway::addRooms(Room* library, Room* bedroom, Room* kitchen, Room* study)
{
	r1 = library;
	r2 = bedroom;
	r3 = kitchen;
	r4 = study;
}

/********************************************************************
** Description: Displays text for entering the hallway.
********************************************************************/
void Hallway::enterRoom()
{
	if (!lightsOn)
	{
		std::cout << "Everything is dark." << std::endl;
		std::cout << "You here a dog whimpering in the distance." << std::endl;
	}
	else
	{
		std::cout << "You here a dog whimpering in the distance." << std::endl;
	}
}

/********************************************************************
** Description: The user decides if the lights get turned on.
********************************************************************/
void Hallway::special()
{
	char option;
	
	if (!lightsOn)
	{
		do
		{
			std::cout << "Do you turn on the lights? (y or n)" << std::endl;
			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (option == 'y')
			{
				lightsOn = true;
				std::cout << "You can see there are four rooms connected to hallway." << std::endl;
				std::cout << "There is a kitchen at the end of the hallway." << std::endl;
				std::cout << "There is two rooms on the left with the doors closed." << std::endl;
				std::cout << "There is one room on the right with the door closed." << std::endl;
			}
			else if (option == 'n')
			{
				std::cout << "You stumble around the hallway." << std::endl;
				std::cout << "You find a kitchen at the end of the hallway." << std::endl;
				std::cout << "You find two doors on the left side of the hallway" << std::endl;
				std::cout << "You find one door on the right side of the hallway" << std::endl;
			}
			else
			{
				std::cout << "Invalid choice. Enter y or n" << std::endl;
			}
		} while (option != 'y' && option != 'n');

		
	}
}

/********************************************************************
** Description: User decides which room to enter.
** Return: Pointer to the room the user enters.
********************************************************************/
Room* Hallway::action()
{
	char option;
	
	do
	{
		std::cout << "Where do you want to go?" << std::endl;
		std::cout << "1) First room on the left." << std::endl;
		std::cout << "2) Second room on the left." << std::endl;
		std::cout << "3) Kitchen." << std::endl;
		std::cout << "4) Room on the right." << std::endl;
		std::cin >> option;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if(option == '1')
		{
			return r1;
		}
		else if(option == '2')
		{
			if (bag->key == true)
			{
				return r2;
			}
			else
			{
				std::cout << "The room is locked." << std::endl;
			}
		}
		else if(option == '3')
		{
			return r3;
		}
		else if(option == '4')
		{
			return r4;
		}
		else
		{
			std::cout << "Invalid Option. Choose 1 - 5" << std::endl;
		}
	} while(option != '1' && option != '3' && option != '4');	
}
		
	