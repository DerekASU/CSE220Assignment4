#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Friends.h"
#include "Menu.h"
#include "User.h"
#include "SystemMain.h"

using namespace std;



int main() {

	System system;
	system.start();
	/*	Menu menu;
	int option = menu.display();
	if(option == 1)
	createUser();
	User nuser("anthony");*/
	//return 0;
}


void System::start()
{
	Menu menu;
	outputBanner("Welcome to my ScrapBook App!");
	initializeUsers();
	authorized = false;
	while (true) {
		int option = menu.display();
		if (option == 1)
			createUser();
		else if (option == 2)
			postMessage();
		else if (option == 3)
			displayWall();
		else if (option == 4)
			displayHome();
		else if (option == 5)
			addFriend();
		else if (option == 6)
			switchUser();
		else if (option == 7)
			removeFriend();
		else if (option == 8)
			displayFriends();
		else if (option == 9){
			quit();
			break;
		}
		else {
			cout << "Error:  Please input an option between 1 to 7" << endl;
		}
	}
}


bool System::validateName(string name) {
	return true;
}

bool System::validateUser(string name) {
	if (userExists(name) == true)
		return false;
	else
		return true;
}


void System::outputBanner(string str) {
	streamsize width = (streamsize)(str.length() + 80) / 2;

	int len = str.length();
	string star = "#";
	for (int i = 0; i < len + 7; i++)
	{
		star = star + "#";
	}
	cout << endl;
	cout << setw(width) << star << endl;
	cout << setw(width) << "#   " + str + "   #" << endl;
	cout << setw(width) << star << endl;
	cout << endl;

}

void System::updateMenu(Menu& m) {

}

void System::initializeUsers() {
	User *nuser = new User("Joe");
	users.push_back(nuser);
	nuser = new User("Bob");
	users.push_back(nuser);
	nuser = new User("Mark");
	users.push_back(nuser);
	nuser = new User("Jane");
	users.push_back(nuser);

}
void System::createUser() {

	cout << "Please enter your name: ";
	string name;
	cin >> name;

	if (validateUser(name) == true)
	{
		User *nuser = new User(name);
		users.push_back(nuser);
		outputBanner("Welcome, " + name);
		currentUser = nuser;
		authorized = true;
	}
	else
		cout << "User already exists !!" << endl;

}


void System::postMessage() {
	if (authorized == false)
	{
		cout << "Error: No user is logged in. Select another option" << endl;
		return;
	}

	cout << "Please enter your message: ";
	string msg;
	cin.ignore();
	getline(cin, msg);
	//string msg = new string(msg1);
	Wall *wall = new Wall(currentUser->getName(), msg);
	wallpage.push_back(wall);
}

void System::displayHome() {
	if (authorized == false)
	{
		cout << "Error: No user is logged in. Select another option" << endl;
		return;
	}
	cout << "(0) Show all messages " << endl;
	cout << "(1) Show only recent messages " << endl << endl;
	cout << "Please enter your choice from the menu above: ";

	int op;
	cin >> op;

	outputBanner(currentUser->getName() + "'s Home Page");
	vector<string> frndlist = currentUser->getFriends();
	if (wallpage.size() == 0)
		return;

	for (int i = wallpage.size() - 1; i >= 0; i--) {
		if (op == 2)
			break;
		Wall* nwall = wallpage[i];
		string wallname = nwall->getwalluser();
		if (wallname.compare(currentUser->getName()) == 0) {
			cout << wallname + ": " + nwall->getmsg() << endl;
			if (op == 1)
				op = 2;
		}
		else {

			for (int j = 0; j < frndlist.size(); j++)
			{
				string frnd = frndlist[j];
				if (wallname.compare(frnd) == 0)
				{
					cout << wallname + ": " + nwall->getmsg() << endl;
					if (op == 1)
						op = 2;

				}
			}
		}
	}
}

void System::displayWall() {
	if (authorized == false)
	{
		cout << "Error: No user is logged in. Select another option" << endl;
		return;
	}
	outputBanner(currentUser->getName() + "'s Wall Page");
	if (wallpage.size() == 0)
		return;
	for (int i = wallpage.size() - 1; i >= 0; i--) {
		Wall* nwall = wallpage[i];
		if (nwall->getwalluser().compare(currentUser->getName()) == 0)
		{
			cout << currentUser->getName() + ": " + nwall->getmsg() << endl;
		}
	}
}

void System::addFriend() {
	if (authorized == false)
	{
		cout << "Error: No user is logged in. Select another option" << endl;
		return;
	}
	string name;
	cout << "Please enter the name of the user to add to your friend list or type \"<menu>\"  to go back: ";
	cin >> name;
	if (userExists(name) == true) {
		bool added = currentUser->addFriend(name);
		if (added == false) {
			cout << currentUser->getName() + " is already friends with " + name << endl;
		}
		else
			cout << "That user has been added to your friends list! " << endl;

	}
	else if (name.compare("menu") == 0) {
	}
	else
		cout << "Invalid User specified: " + name + " does not exist" << endl;
}


void System::removeFriend() {
	if (authorized == false)
	{
		cout << "Error: No user is logged in. Select another option" << endl;
		return;
	}
	string name;
	cout << "Please enter the name of the user to remove from your friend list or type \"<menu>\"  to go back: ";
	cin >> name;
	if (userExists(name) == true) {
		bool removed = currentUser->removeFriend(name);
		if (removed == false) {
			cout << currentUser->getName() + " wasn't friends with " + name << endl;
		}
		else
			cout << "That user has been removed from your friends list! " << endl;

	}
	else if (name.compare("menu") == 0) {
	}
	else
		cout << "Invalid User specified: " + name + " does not exist" << endl;
}

void System::displayFriends() {
	if (authorized == false)
	{
		cout << "Error: No user is logged in. Select another option" << endl;
		return;
	}
	//string name;
	//cout << "Please enter the name of the user to add to your friend list or type \"<menu>\"  to go back: ";
	//cin >> name;
	//if (userExists(name) == true) {
		bool display = currentUser->displayFriends();
		if (display == false) {
			cout << currentUser->getName() + " has no friends"<< endl;
		}
		else
			cout << "Friends displayed! " << endl;

	//}
	//else if (name.compare("menu") == 0) {
	//}
	//else
		//cout << "Invalid User specified: " + name + " does not exist" << endl;
}

void System::switchUser() {
	while (true) {
		cout << "Please enter the name of the user to switch to or type \"<menu>\" to go back: ";
		string name;
		cin >> name;
		if (userExists(name) == true) {
			currentUser = getUser(name);
			authorized = true;
			outputBanner("Welcome Back, " + name);
			break;
		}
		else if (name.compare("menu") == 0)
		{
			break;
		}
		else
			cout << "Invalid User Name specified " + name + " does not exist" << endl;
	}
}

void System::quit() {
	outputBanner("Thank you for using my ScrapBook");
}

bool System::userExists(string name) {
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName().compare(name) == 0)
			return true;
	}
	return false;
}


User* System::getUser(string name) {
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName().compare(name) == 0)
			return users[i];
	}
	return NULL;
}