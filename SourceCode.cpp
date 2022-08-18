#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <typeinfo>

using namespace std;

// Function prototypes
void CreateInventory();
// Add item
// Remove item (id)
// See Inventory

int main()
{
	// Welcome the user to the program
	cout << "\nWellcome to this Inventory Management System" << endl;

	// When first staring the program we check if there is a file to read from
	try
	{
		ifstream reader("inventory.txt");

		// Throw exception if file doesn't exist or close stream if it does
		(!reader) ? throw logic_error("Inventory file not found") : reader.close();
	}
	catch(exception &e)
	{
		// Inform the user
		cerr << "Error: " << e << endl;

		// Ask user if they wish to generate a new inventory
		string answer;

		cout << "Do you wish to generate a new file?";

		// Make the user input case independent
		cin >> uppercase >> answer;
		
		// Check the user's answer
		switch (answer)
		{
		case "YES":
			// Generate new inventory
			CreateInventory();
			break;
		case "NO":
			// Go to close program message
			break;
		default:
			// Incorrect inptu
			cout << "Input not recognised. Please try again";
			break;
		}

	}

	cout << "This program has reached the end. Press return to exit.";
	// Need to implement a method to not close the console automaticaly so the user can read any last messages before closing
	return 0;
}