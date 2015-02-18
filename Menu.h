#ifndef MENU_H
#define MENU_H
#include <string>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

/**
Class Name      :       Menu
Purpose         :       Display a list of options to the user
Input           :       User's Choice for activity to be performed
*/

class Menu
{
public:
	void addOption(int, string);
	void clearMenu();
	void removeOption(int);
	int display();

	/**
	Function Name   :       setTitle
	Purpose         :       Sets the title of Menu list
	Input           :       Menu title to be displayed
	*/
	inline void setTitle(string newTitle) { title = newTitle; }

private:
	map<int, string> options; // A map of the options.
	string title; // Title that is displayed above the menu.
	void getTitle();
	int getChoice();
};

#endif