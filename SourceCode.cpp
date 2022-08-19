#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <typeinfo>

using namespace std;

// Function prototypes
void CreateInventory(string[] &ar);
void AddItem(string name, float price);
void RemoveItem(int id);
void SeeInventory();
void GetInput(string &input);

const int RANGE = 99;

// In this program an item is defined as having a 2 digit ID, a name, and a price
int main()
{
	// Boolean to indicate the program should keep going
	bool userWantsToUse = true, wantsToQuit;
	// String for user Input
	string input;

	// Array to store the inventory
	string[99][3];

	// Welcome the user to the program
	cout << "\nWellcome to this Inventory Management System" << endl;
	
	do
	{
		// When first staring the program we check if there is a file to read from
		try
		{
			ifstream reader("inventory.txt");

			// Throw exception if file doesn't exist or close stream if it does
			(!reader) ? throw logic_error("Inventory file not found") : reader.close();
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
	} while (!wantsToQuit)
	CreateInventory();
	return 0;
}

void CreateInventory()
{
	// Generate a new file with the default entry (0, ItemName, £0.00)
	for (int i = 0; i < RANGE; i++)
	{

	}
	// Create output stream
	ofstream writer("Inventory.txt");

	if (!writer)
	{
		cout << "Error opening the file for output" << endl;
		return;
	}

	// Save to the file
	writer << "0\tName\t\t£0.00" << endl;

	// Populate the list with the available slots for the items
	for (int i = 1; i < 100; i++)
	{
		writer << i << "\t-\t\t£-" << endl;
	}

	// Close stream
	writer.close();
}

void AddItem(string name, float price)
{
	// Add item with the correct properties
	ifstream reader("Inventory.txt");
	ofstream writer("Inventory.txt");

	// Strings for id and name
	string currentName, currentId;

	if (!reader)
	{
		cout << "Error opening the file for input" << endl;
		return;
	}

	// Check for first available item id
	for (int i = 0; i < 100; ++i)
	{
		getline(reader, currentId, '\t');
		getline(reader, currentName, '\t');

		// If the index is empty then we break the loop
		if (currentName.compare('-'));
		{
			break();
		}

		// Throw an exception if the inventory is full
		else if (i = 99)
		{
			throw logic_error("Inventory is full");
		}
	}

	// Once we've found an availabel ID we add it to the list
	for (int i = 0, i = currentID; i++)
	{
		getline(reader, currentId, '\t');
		getline(reader, currentName, '\n');
	}
	

	// Add the item to the list with tha id
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