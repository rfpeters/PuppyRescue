/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The user finds a leash on a table.  The least is 
**    needed to rescue the dog.
********************************************************************/
#include "Library.hpp"

/********************************************************************
** Description: Constructor, sets name and pointer to inventory.
** Param b: Pointer to Inventory
********************************************************************/
Library::Library(Inventory* b)
{
	name = "Library";
	bag = b;
}

/********************************************************************
** Description: Instantiates links to connecting rooms.
** Param hallway: Pointer to Hallway
********************************************************************/
void Library::addRooms(Room* hallway)
{
	r1 = hallway;
}

/********************************************************************
** Description: Displays text for entering the library.
********************************************************************/
void Library::enterRoom()
{
	std::cout << "The walls are covered in books" << std::endl;
	std::cout << "You see table off to the left." << std::endl;
}

/********************************************************************
** Description: The user decides if the leash is picked up.
********************************************************************/
void Library::special()
{
	char option;

	if (bag->leash == false)
	{
		do
		{
			std::cout << "You see a leash on a table." << std::endl;
			std::cout << "Pick up the leash? (y or n)" << std::endl;
			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (option == 'y')
			{
				std::cout << "You take the leash." << std::endl;
				bag->leash = true;
			}
			else if (option == 'n')
			{
				std::cout << "You leave the leash on the table." << std::endl;
			}
			else
			{
				std::cout << "Invalid choice. Enter y or n" << std::endl;
			}
		} while (option != 'y' && option != 'n');
	}
	else
	{
		std::cout << "You can't find anything else to do in the library." << std::endl;
	}
}

/********************************************************************
** Description: User decides to leave the room or not.
** Return: Pointer to Hallway if user leaves.
**         Pointer to Library if user stays.
********************************************************************/
Room* Library::action()
{
	char option;

	do
	{
		std::cout << "Do you want to leave the library? (y or n)" << std::endl;
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
	} while (option != 'y' && option != 'n');;
}