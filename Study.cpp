/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The user finds a key in a desk.  The key is used to 
**    unlock the bedroom.
********************************************************************/
#include "Study.hpp"

/********************************************************************
** Description: Constructor, sets name and pointer to inventory.
** Param b: Pointer to Inventory
********************************************************************/
Study::Study(Inventory* b)
{
	name = "Study";
	bag = b;
}

/********************************************************************
** Description: Instantiates links to connecting rooms.
** Param hallway: Pointer to Hallway
********************************************************************/
void Study::addRooms(Room* hallway)
{
	r1 = hallway;
}

/********************************************************************
** Description: Displays text for entering the study.
********************************************************************/
void Study::enterRoom()
{
	std::cout << "There is a large desk in the middle of the room." << std::endl;
	std::cout << "You search the desk." << std::endl;
}

/********************************************************************
** Description: The user decides if key is picked up.
********************************************************************/
void Study::special()
{
	char option;

	if (bag->key == false)
	{
		do
		{
			std::cout << "There is a key in the desk." << std::endl;
			std::cout << "Pick up the key? (y or n)" << std::endl;
			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (option == 'y')
			{
				std::cout << "You take the key." << std::endl;
				bag->key = true;
			}
			else if (option == 'n')
			{
				std::cout << "You leave the key in the desk." << std::endl;
			}
			else
			{
				std::cout << "Invalid choice. Enter y or n" << std::endl;
			}
		} while (option != 'y' && option != 'n');
	}
	else
	{
		std::cout << "You can't find anything else to do in the study." << std::endl;
	}
}

/********************************************************************
** Description: User decides to leave the room or not.
** Return: Pointer to Hallway if user leaves.
**         Pointer to Study if user stays.
********************************************************************/
Room* Study::action()
{
	char option;

	do
	{
		std::cout << "Do you want to leave the study? (y or n)" << std::endl;
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