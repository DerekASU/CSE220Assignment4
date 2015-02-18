#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <string>
#include "Wall.h"
#include "User.h"
#include "Menu.h"
using namespace std;
class System
{
	friend bool msgPostedByUser(string, string);

public:
	void start();
	bool userExists(string);
	User* getUser(string);
	string newestMessage(string);
private:
	vector<User*> users; // A vector containing all the users.
	string messageBuffer; // The main message buffer.
	bool authorized; // Whether there is an active user logged in.
	User *currentUser; // A pointer to the current user.
	bool validateName(string);
	bool validateUser(string);
	void outputBanner(string);
	void updateMenu(Menu&);
	void initializeUsers();
	void createUser();
	void main();
	void postMessage();
	void displayWall();
	void displayHome();
	void addFriend();
	void switchUser();
	void quit();
	void removeFriend();
	void displayFriends();
	vector<Wall*> wallpage;

};
#endif
