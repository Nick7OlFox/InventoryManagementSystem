#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <typeinfo>

using namespace std;

// Function prototypes
void CreateInventory();
void AddItem(int id, string name, float price);
void RemoveItem(int id);
void SeeInventory();
void GetInput(string &input);

// In this program an item is defined as having a 2 digit ID, a name, and a price
int main()
{
	// Boolean to indicate the program should keep going
	bool userWantsToUse = true, wantsToQuit;
	// String for user Input
	string input;
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
	return 0;
}