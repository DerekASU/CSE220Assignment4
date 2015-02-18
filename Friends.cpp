#include <iostream>
#include <string>
#include <vector>
#include "Friends.h"
using namespace std;
/**
Constructor Name:       Friends
Purpose         :       Constructor for the Friends class for User <user>
Parameter       :       type--string    name--user
*/
Friends::Friends(string user) : user(user) //member initialization list
{

	//empty body
}


/**
Function Name   :       friendExists
Purpose         :       Checks if the name entered is a friend or not
*/
bool Friends::friendExists(string userFriend)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i] == userFriend)
			return true;
	}
	return false;
}

/**
Function Name   :       addFriend
Purpose         :       Add a user to the Friends
*/
bool Friends::addFriend(string user2)
{
	if (friendExists(user2)) //if entered name is already a friend
		return false;           //do not do anything
	friends.push_back(user2);  //else add nameof friend to the list
	return true;                    //push_back is a function of vector class
}
bool Friends::removeFriend(string user2)
{
	if (!friendExists(user2)){ //if entered name is not a friend
		return false;
	}  //do not do anything
	for (int i = 0; i < friends.size(); i++)
		if (user2 == friends.at(i)){
		friends.erase(friends.begin() + i);
		//
		return true;
		}//p

}
bool Friends::display()
{
	if (friends.size()==0){ //if entered name is not a friend
		return false;
	}  //do not do anything
	for (int i = 0; i < friends.size(); i++){
		cout << i+1 << ": " << friends.at(i) << endl;
		}//p
	return true;

}
