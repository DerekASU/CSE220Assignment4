#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Menu.h"

using namespace std;

/**
Function Name   :       addOption
Purpose         :       Add an option to Menu list
*/
void Menu::addOption(int key, string value)
{
	options[key] = value;
}

/**
Function Name   :       clearMenu
Purpose         :       Clears the Menu list
*/
void Menu::clearMenu()
{
	options.clear();
}

/**
Function Name   :       getTitle
Purpose         :       Display the Menu title
*/
void Menu::getTitle()
{
	cout << "-------" << title << "-------" << endl;
}

/**
Function Name   :       getResponse
Purpose         :       Retrieve the user choice from MEnu selection
*/

/**
Function        :       display
Purpose         :       Displays the menu and gets the option selected by the user.
*/
int Menu::display()
{
	int option;
	cout << endl;
	cout << "(1) Create New User" << endl;
	cout << "(2) Post Message" << endl;
	cout << "(3) Display Wall Page" << endl;
	cout << "(4) Display Home Page" << endl;
	cout << "(5) Add Friend" << endl;
	cout << "(6) Switch to Existing User" << endl;
	cout << "(7) remove friend" << endl;
	cout << "(8) display list of friends" << endl;
	cout << "(9) Quit Scrapbook" << endl << endl;
	cout << "Please enter your choice from the menu above: ";
	cin >> option;
	cout << endl;
	return option;
}
