#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
#include "Friends.h"

using namespace std;

class User
{
public:
	User(string);
	bool addFriend(string);
	bool removeFriend(string); 
	bool displayFriends();
	
	/**
	Function Name   :       User
	Purpose         :       retrieves given user name
	*/
	inline string getName() { return name; }

	bool isFriend(string);
	vector<string> getFriends();
private:
	string name; // The name of the user.
	Friends friends; // Class composition -- an object of Friends class is made as a data member of User class

};
#endif
