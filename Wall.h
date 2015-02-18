
#ifndef WALL_H
#define WALL_H
#include <sstream>
#include <string>
#include "User.h"

using namespace std;

class Wall
{
public:
	Wall(string, string);
	void addMessage(string);
	void display();
	bool msgPostedByUser(string, string);
	inline string getwalluser() { return user; }
	inline string getmsg() { return messageBuffer; }

private:

	string user; // Name of the user.
	string messageBuffer; // A reference to the main messageBuffer.
	string allMessages();
};
#endif
