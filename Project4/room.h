/*
 * Project 4 : Room Header
 * Declares variables and functions for room class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */
#pragma once

#include "gameobject.h"
#include "item.h"

#include <iostream>
#include <string>
using namespace std;

/*
 * Room
 * Class derived from GameObject class
 * Has a description and four room pointers
 * Contains setters and getters for description, pointers, puzzle text, and passphrase.
 * Contains functions for returning and removing items in array
 */

class Room : public GameObject{
	private:
		string description; //Description of room
		string puzzleText; //Text for puzzle to unlock the next room
        int passphrase; //Answer to puzzle
        int itemNum; //Number of items stored in the room at any point
		Room* northRoom; //Pointer to north room
		Room* southRoom; //Pointer to south room
		Room* eastRoom; //Pointer to east room
		Room* westRoom; //Pointer to west room
		Item* roomItems; //Array to hold room items
	public:
		Room(); //Default constructor
		Room(string newName, string newDescription, string newPuzzleText, int passphrase, Item* newRoomItems, int newNumItem); //Overloaded constructor

		void setDescription(string newDescription); //Sets room description
		string getDescription(); //Returns room description as a string
		string getRoomName(); //Returns room name as a string

		void setPuzzleText(string newPuzzleText); //Sets puzzle text
		string getPuzzleText(); //Returns puzzle text as a string

		void setPassphrase(int newPassphrase); //Sets pass phrase to unlock next room
		int getPassphrase(); //Returns pass phrase as an int

		void getRoomItems(); //Displays all items in room array on the screen
		int getNumItems(); //Returns number of currently held items as an int
		Item takeRoomItem(int itemIndex); //Returns item at specified item index
		void removeItem(int itemIndex); //Removes item from room array at specified item index

		void setNorthRoom(Room* newNorthRoom); //Sets pointer for north room
		Room* getNorthRoom(); //Returns pointer to north room

		void setSouthRoom(Room* newSouthRoom); //Sets pointer for south room
		Room* getSouthRoom(); //Returns pointer to south room

		void setEastRoom(Room* newEastRoom); //Sets pointer for east room
		Room* getEastRoom(); //Returns pointer to east room

		void setWestRoom(Room* newWestRoom); //Sets pointer for west room
		Room* getWestRoom(); //Returns pointer to west room

		void describe(); //Displays name and description to screen
};
