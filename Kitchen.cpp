/********************************************************************
** Author: Ryan Peters
** Date: 12/06/15
** Description: The user finds treats in the pantry.  The treates are
**    needed to rescue the dog.
********************************************************************/
#include "Kitchen.hpp"

/********************************************************************
** Description: Constructor, sets name and pointer to inventory.
** Param b: Pointer to Inventory
********************************************************************/
Kitchen::Kitchen(Inventory* b)
{
	name = "Kitchen";
	bag = b;
}

/********************************************************************
** Description: Instantiates links to connecting rooms.
** Param hallway: Pointer to Hallway
********************************************************************/
void Kitchen::addRooms(Room* hallway)
{
	r1 = hallway;
}

/********************************************************************
** Description: Displays text for entering the kitchen.
********************************************************************/
void Kitchen::enterRoom()
{
	std::cout << "The cupboards look empty." << std::endl;
	std::cout << "You think you see something in the pantry" << std::endl;
}

/********************************************************************
** Description: The user decides if the treats are picked up.
********************************************************************/
void Kitchen::special()
{
	char option;

	if (bag->treat == false)
	{
		do
		{
			std::cout << "You search the pantry and find dog treats." << std::endl;
			std::cout << "Pick up the treats? (y or n)" << std::endl;
			std::cin >> option;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (option == 'y')
			{
				std::cout << "You take the treats." << std::endl;
				bag->treat = true;
			}
			else if (option == 'n')
			{
				std::cout << "You leave the treats in the pantry." << std::endl;
			}
			else
			{
				std::cout << "Invalid choice. Enter y or n" << std::endl;
			}
		} while (option != 'y' && option != 'n');
	}
	else
	{
		std::cout << "You can't find anything else to do in the kitchen." << std::endl;
	}
}

/********************************************************************
** Description: User decides to leave the room or not.
** Return: Pointer to Hallway if user leaves.
**         Pointer to Kitchen if user stays.
********************************************************************/
Room* Kitchen::action()
{
	char option;

	do
	{
		std::cout << "Do you want to leave the kitchen? (y or n)" << std::endl;
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