#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <typeinfo>
#include <sstream>

using namespace std;

// Function prototypes
void CreateInventory(string(&rInv)[99][2]);
void GetInventory(string(&rInv)[99][2]);
void SaveInventory(string(&rInv)[99][2]);
void AddItem(string(&rInv)[99][2], string, float);
void RemoveItem(int);
void SeeInventory();
void GetInput(string&);

const int RANGE = 99;

// In this program an item is defined as having a 2 digit ID, a name, and a price
int main()
{
	// Boolean to indicate the program should keep going
	bool userWantsToUse = true, wantsToQuit;
	// String for user Input
	string input;

	// Array to store the inventory
	string inventory [99][2];

	// Welcome the user to the program
	cout << "\nWellcome to this Inventory Management System" << endl;
	/*
	do
	{
		// When first staring the program we check if there is a file to read from
		try
		{
			ifstream reader("inventory.txt");

			// Throw exception if file doesn't exist or close stream if it does
			(!reader) ? throw logic_error("Inventory file not found") : GetInventory(inventory);
		}
		catch (exception& e)
		{
			// Inform the user
			cerr << "Error: " << e << endl;

			// Ask user if they wish to generate a new inventory
			cout << "Do you wish to generate a new file?";

			GetInput(input);

			// Check the user's answer
			bool hasAnswered = false;
		}

		do
		{
			switch (input)
			{
			case YES:
				// Generate new inventory
				CreateInventory();
				// Set bool to true
				hasAnswered = true;
				break;
			case NO:
				// Set bool to true and go to close program message
				hasAnswered = true;
				userWantsToUse = false;
				break;
			default:
				// Incorrect inptut
				cout << "Input not recognised. Please try again";
				break;
			}
		} while (!hasAnswered);

		while (userWantsToUse)
		{
			GetInput(input);

			// Check user input
			switch (input)
			{
			case ADD:
				// Get Item detials
				// Add item to the file
				AddItem(id, name, price);
				break();
			case REMOVE:
				// Get Item Id
				// Remove item from the file
				RemoveItem(id);
				break();
			case SEE:
				// Show all of the items
				SeeInventory();
				break();
			case LEAVE:
				// Change boolean to leave the program
				userWantsToUse = false;
				break();
			default:
				// Input error
				// Ask for input again
				break;
			}
		}

		cout << "This program is about to close. Write QUIT to accept this. - ";
		GetInput(input);
		(input.compare("QUIT") ? wantsToQuit = true : wantsToQuit = false;
	} while (!wantsToQuit)*/
	CreateInventory(inventory);
	AddItem(inventory, "Pencil", 0.35);
	AddItem(inventory, "Dildo", 98.67);
	return 0;
}

void CreateInventory(string(&rInv)[99][2])
{
	// Generate the array with the data
	for (int i = 0; i < RANGE; i++)
	{
		rInv[i][0] = "-";
		rInv[i][1] = "£0.00";
	}
	
	// Save onto file
	SaveInventory(rInv);
}

void SaveInventory(string(&rInv)[99][2])
{
	ofstream writer("Inventory.txt");

	if (!writer)
	{
		throw logic_error("Error saving into file");
	}

	// Save every entry into the file
	for (int i = 0; i < RANGE; i++)
	{
		writer << i+1 << "\t" << rInv[i][0] << "\t" << rInv[i][1] << endl;
	}

	// Close the stream
	writer.close();
}

void AddItem(string(&rInv)[99][2] ,string name, float price)
{
	// Add item with the correct properties
	int firstAvailableIndex;

	for (firstAvailableIndex = 0; firstAvailableIndex < RANGE; firstAvailableIndex++)
	{
		// If the slot is empty break the loop
		if (rInv[firstAvailableIndex][0] == "-")
		{
			break;
		}
		// Throw exception if there are no avaliable slots
		else if(firstAvailableIndex == RANGE - 1)
		{
			throw logic_error("There are no available slots to save this new item to");
		}
	}

	

	// Cast float into a string
	stringstream stream;
	string priceString;

	stream << price;
	stream >> priceString;

	priceString = "£" + priceString;

	// Add values to the array
	rInv[firstAvailableIndex][0] = name;
	rInv[firstAvailableIndex][1] = priceString;
	
	SaveInventory(rInv);
}

void RemoveItem(int id)
{
	// Look for the id location
	// Empty that entry
}

void SeeInventory()
{
	// Print all of the inventory on the console
}

void GetInput(string& input)
{
	// Get the user input
	// Convert it into all Uppercase
}