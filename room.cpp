/*
 * Project 4 : Room Source
 * Contains functions for Room class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */

#include "room.h"
#include "item.h"

/*
 * Room
 * A class derived from the GameObject class
 * Has a description and four room pointers
 * Contains setters and getters for description, pointers, puzzle text, and passphrase.
 * Contains functions for returning and removing items in array
 */

Room::Room () //Default constructor
: GameObject("UNAMED ROOM"), description("AN EMPTY ROOM"), puzzleText("PUZZLE TEXT"), passphrase(0), northRoom(0), southRoom(0), eastRoom(0), westRoom(0), itemNum(0){
}

Room::Room (string newName, string newDescription, string newPuzzleText, int newPassphrase, Item* newRoomItems, int newItemNum) //Overloaded constructor
: GameObject(newName), description(newDescription), puzzleText(newPuzzleText), passphrase(newPassphrase), northRoom(0), southRoom(0), eastRoom(0), westRoom(0), roomItems(newRoomItems), itemNum(newItemNum){
}

void Room::setDescription(string newDescription){ //Sets room description
	description = newDescription;
}

string Room::getDescription(){ //Returns room description as a string
	return description;
}

string Room::getRoomName(){ //Returns room name as a string
    return getName();
}

void Room::setPuzzleText(string newPuzzleText){ //Sets puzzle text
	puzzleText = newPuzzleText;
}

string Room::getPuzzleText(){ //Returns puzzle text as a string
	return puzzleText;
}

void Room::getRoomItems(){ //Displays all items in room array on the screen
    for (int i=0; i<itemNum; i++)
    {
        cout << i+1 << ". " << roomItems[i].getName() << endl;
    }
}

int Room::getNumItems(){ //Returns number of currently held items as an int
    return itemNum;
}

Item Room::takeRoomItem(int itemIndex){ //Returns item at specified item index
    return roomItems[itemIndex];
}

void Room::removeItem(int itemIndex) //Removes item from room array at specified item index
{
    for (int i=itemIndex; i<itemNum-1; i++)
    {
        roomItems[i] = roomItems[(i+1)];
    }
    itemNum--;
}

void Room::setPassphrase(int newPassphrase){  //Sets pass phrase to unlock next room
	passphrase = newPassphrase;
}

int Room::getPassphrase(){ //Returns pass phrase as an int
	return passphrase;
}

void Room::setNorthRoom(Room* newNorthRoom){ //Sets pointer for north room
    northRoom = newNorthRoom;
}

Room* Room::getNorthRoom(){ //Returns pointer to north room
    return northRoom;
}

void Room::setSouthRoom(Room* newSouthRoom){ //Sets pointer for south room
    southRoom = newSouthRoom;
}

Room* Room::getSouthRoom(){ //Returns pointer to south room
    return southRoom;
}

void Room::setEastRoom(Room* newEastRoom){ //Sets pointer for east room
    eastRoom = newEastRoom;
}

Room* Room::getEastRoom(){ //Returns pointer to east room
    return eastRoom;
}

void Room::setWestRoom(Room* newWestRoom){ //Sets pointer for west room
    westRoom = newWestRoom;
}

Room* Room::getWestRoom(){ //Returns pointer to west room
    return westRoom;
}

void Room::describe(){ //Displays name and description to screen
    cout << getName() << "." <<  endl;
    cout << description << endl;
}
