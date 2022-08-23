#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <typeinfo>
#include <sstream>
#include <algorithm>

using namespace std;

// Function prototypes
// File Management
void LoadInventory(string(&rInv)[99][2]);
void SaveInventory(string(&rInv)[99][2]);

// Program Functions
void CreateInventory(string(&rInv)[99][2]);
void AddItem(string(&rInv)[99][2]);
void RemoveItem(string(&rInv)[99][2]);
void SeeInventory(string(&rInv)[99][2]);

// Input Management
void GetCommand(string(&rInv)[99][2]);

// Inventory size
const int RANGE = 99;

// In this program an item is defined as having a 2 digit ID, a name, and a price
int main()
{
	// Boolean to indicate the program should keep going
	bool userWantsToUse = true, wantsToQuit;

	// Array to store the inventory
	string inventory [99][2];

	// Welcome the user to the program
	cout << "\nWellcome to this Inventory Management System" << endl;
	
	// Get or create new inventory
	try
	{
		LoadInventory(inventory);
	}
	catch (exception& e)
	{
		CreateInventory(inventory);
	}

	GetCommand(inventory);

	return 0;
}

// --------------------------------------------------------------------------------------------
//										FILE MANAGEMENT
// --------------------------------------------------------------------------------------------
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
		writer << i + 1 << "\t" << rInv[i][0] << "\t" << rInv[i][1] << endl;
	}

	// Close the stream
	writer.close();
}

void LoadInventory(string(&rInv)[99][2])
{
	ifstream reader("Inventory.txt");

	if(!reader)
	{
		throw logic_error("Error loading the file");
	}

	// Save every entry into an array
	for (int i = 0; i < RANGE; i++)
	{
		// Ignore the first value as that's the ID and it will be saved as the array index minus 1
		reader.ignore(3, '\t');

		// Save data into array
		getline(reader, rInv[i][0], '\t');
		getline(reader, rInv[i][1], '\n');
	}

	// Close the stream
	reader.close();
}

// --------------------------------------------------------------------------------------------
//										PROGRAM FUNCTIONS
// --------------------------------------------------------------------------------------------
void CreateInventory(string(&rInv)[99][2])
{
	// Generate the array with the data
	for (int i = 0; i < RANGE; i++)
	{
		rInv[i][0] = "-";
		rInv[i][1] = "0.00GBP";
	}
	
	// Save onto file
	try
	{
		SaveInventory(rInv);
	}
	catch (exception &e)
	{
		cerr << "ERROR: " << e.what() << endl;
		return;
	}

	cout << endl << "New inventory created" << endl << endl;

	cout.width(40);
	cout.fill('-');
	cout << "-" << endl << endl;

	// Recieve more input
	GetCommand(rInv);
}

void AddItem(string(&rInv)[99][2])
{
	string name, priceS;
	stringstream stream;
	float price;

	// Get item data
	cout << "What's the name of the item you want to add? ";
	getline(cin, name);

	cout << "How much are you charging for this item? ";
	getline(cin, priceS);

	try
	{
		stream << priceS;
		stream >> price;

		stream.str();
		stream.clear();
	}
	catch (exception &e)
	{
		cout << "There was an error with the price introduced." << endl;

		return;
	}

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
	string priceString;

	stream.precision(2);
	stream << fixed << price;
	stream >> priceString;

	stream.str();
	stream.clear();

	priceString += "GBP";

	// Add values to the array
	rInv[firstAvailableIndex][0] = name;
	rInv[firstAvailableIndex][1] = priceString;
	
	try
	{
		SaveInventory(rInv);
	}
	catch (exception &e)
	{
		cerr << "ERROR: " << e.what() << endl;
		return;
	}

	cout << "Item Added" << endl << endl;

	cout.width(40);
	cout.fill('-');
	cout << "-" << endl << endl;

	// Recieve more input
	GetCommand(rInv);
}

void RemoveItem(string(&rInv)[99][2])
{
	string idS;
	stringstream stream;
	int id;
	bool validInput = true;

	do
	{
		// Get ID
		cout << "What's the ID of the item you wish to remove? ";
		getline(cin, idS);

		stream << idS;
		stream >> id;

		stream.str();
		stream.clear();

		// Present the item detail and await for user confirmation to remove them
		cout << "Name: " << rInv[--id][0] << endl;
		cout << "Price: " << rInv[id][1] << endl << endl;

		cout << "Is this the item you're trying to remove? - ";

		// TEMPORARY
		string answer;
		getline(cin, answer);

		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

		if (answer == "YES")
		{
			validInput = true;

			rInv[id][0] = "-";
			rInv[id][1] = "0.00GBP";

			try
			{
				SaveInventory(rInv);
			}
			catch (exception& e)
			{
				cerr << "ERROR: " << e.what() << endl;
				return;
			}

			cout << endl << "Item removed" << endl << endl;
		}
		else if (answer == "NO")
		{
			validInput = true;

			RemoveItem(rInv);
		}
		else
		{
			cout << "Invalid input. Please try again.";
			validInput = false;
		}
	} while (!validInput);

	cout.width(40);
	cout.fill('-');
	cout << "-" << endl << endl;

	// Recieve more input
	GetCommand(rInv);
}

void SeeInventory(string(&rInv)[99][2])
{
	// Print all of the inventory on the console
	try
	{
		LoadInventory(rInv);
	}
	catch (exception &e)
	{
		cerr << "ERROR: " << e.what() << endl;
		return;
	}

	cout << "This is your current inventory:" << endl << endl;

	for (int i = 0; i < RANGE; i++)
	{
		// Only print slots that have an item
		if (rInv[i][0] != "-")
		{
			// Print data
			cout << "Item ID: " << i + 1 << endl;
			cout << "Name: " << rInv[i][0] << endl;
			cout << "Price: " << rInv[i][1] << endl << endl; // Add a blank line in between items
		}
	}
	
	cout.width(40);
	cout.fill('-');
	cout << "-" << endl << endl;

	// Recieve more input
	GetCommand(rInv);
}

// --------------------------------------------------------------------------------------------
//										INPUT MANAGEMENT
// --------------------------------------------------------------------------------------------
void GetCommand(string(&rInv)[99][2])
{
	string input;
	stringstream stream;

	cout << "Please indicate what action you'd like the program to do." << endl;
	cout << "(Use HELP to see all possible commands)" << endl;

	// Get the command in uppercase
	getline(cin, input);

	transform(input.begin(), input.end(), input.begin(), ::toupper);

	cout.width(40);
	cout.fill('-');
	cout << endl << "-" << endl << endl;


	if (input == "ADD ITEM")
	{
		try
		{
			AddItem(rInv);
		}
		catch (exception& e)
		{
			cerr << "ERROR: " << e.what() << endl;
		}
	}
	else if (input == "REMOVE ITEM")
	{
		RemoveItem(rInv);
	}
	else if (input == "SEE INVENTORY")
	{
		SeeInventory(rInv);
	}
	else if (input == "CREATE NEW INVENTORY")
	{
		// Ensure the user wishes to erase the current inventory
		cout << "Are you sure you want to create a new inventory on top of the current one? [THIS ACTION IS NON REVERSABLE] " << endl;

		// Get answer
		string answer;
		getline(cin, answer);

		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

		if (answer == "YES")
		{
			CreateInventory(rInv);
		}
		else
		{
			cout << "Inventory not erased" << endl;
		}

		cout.width(40);
		cout.fill('-');
		cout << endl << "-" << endl << endl;
	}
	else if (input == "HELP")
	{
		cout << "Here are the commands you can introduce:" << endl;
		cout << "ADD ITEM - Add an item to your current inventory." << endl;
		cout << "REMOVE ITEM - Remove item from the current inventory." << endl;
		cout << "SEE INVENTORY - Display all of the current items in your inventory." << endl;
		cout << "CREATE NEW INVENTORY - Erase the current inventory and creates a new one in its place." << endl;
		cout << "HELP - Display all of the possible commands the program can execute" << endl;
		cout << "EXIT - Exit the program." << endl;
		cout.width(40);
		cout.fill('-');
		cout << endl << "-" << endl << endl;

		GetCommand(rInv);
	}
	else if (input == "EXIT")
	{
		// Ensure the user wishes to erase the current inventory
		cout << "Are you sure you want to quit? " << endl;

		// Get answer
		string answer;
		getline(cin, answer);

		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

		if (answer == "YES")
		{
			return;
		}
		else
		{
			GetCommand(rInv);
		}
	}
	else
	{
		cout << "Invalid Input, please try again"<< endl;

		// Call function again
		GetCommand(rInv);
	}
}