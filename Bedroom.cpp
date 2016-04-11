/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The dog is located in the bedroom.  You need the key
**    to enter the room, and treats and the leash to rescue the dog.
********************************************************************/
#include "Bedroom.hpp"

/********************************************************************
** Description: Constructor, sets name and pointer to inventory.
** Param b: Pointer to Inventory
********************************************************************/
Bedroom::Bedroom(Inventory* b)
{
	name = "Bedroom";
	bag = b;
}

/********************************************************************
** Description: Instantiates links to connecting rooms.
** Param hallway: Pointer to Hallway
********************************************************************/
void Bedroom::addRooms(Room* hallway)
{
	r1 = hallway;
}

/********************************************************************
** Description: Displays text for entering the bedroom.
********************************************************************/
void Bedroom::enterRoom()
{
	std::cout << "You hear whimpering coming from under the bed." << std::endl;
	std::cout << "You look under the bed and find a dog that looks frightened." << std::endl;
	std::cout << "You try to get the dog to come out." << std::endl;
}

/********************************************************************
** Description: Function for rescuing the dog.  Actions are based
**    on items in the Inventory.
********************************************************************/
void Bedroom::special()
{
	
	if (bag->treat == false)
	{
		std::cout << "The dog does not respond." << std::endl;
		std::cout << "Maybe the dog will come out if you had something to give it." << std::endl;
	}
	else if (bag->treat == true)
	{
		std::cout << "The dog comes out to take the treat." << std::endl;
		if (bag->leash == true)
		{
			std::cout << "You put the leash on the dog." << std::endl;
			bag->dog = true;
		}
		else
		{
			std::cout << "The dog goes back under the bed." << std::endl;
			std::cout << "Maybe if you had something to secure the dog it will come with you." << std::endl;
		}
	}
}

/********************************************************************
** Description: User decides to leave the room or not.
** Return: Pointer to Hallway if user leaves.
**         Pointer to Bedroom if user stays.
********************************************************************/
Room* Bedroom::action()
{
	char option;

	do
	{
		std::cout << "Do you want to leave the bedroom? (y or n)" << std::endl;
		std::cin >> option;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (option == 'y')
		{
			return r1;
		}
		else if (option == 'n')
		{
			return this;
		}
		else
		{
			std::cout << "Invalid choice. Enter y or n" << std::endl;
		}
	} while (option != 'y' && option != 'n');
}