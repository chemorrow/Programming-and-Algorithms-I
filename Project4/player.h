/*
 * Project 4 : Player Header
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
#include <vector>
using namespace std;

/*
 * Player
 * Class derived from GameObject class
 * Has gold values and vector for each player
 * Has setter/getters for gold and vectors
 */

class Player : public GameObject{
	private:
	    int gold; //Represents the amount of gold each player currently holds
	    vector<Item> playerItems; //This vector holds all of the players items
	public:
	    Player(); //Default constructor
	    Player(string newName, int newGold, Item newItem); //Overloaded constructor, passed name, gold and starting item.

	    void addGold(int newGold); //Adds gold after transaction
	    void removeGold(int newGold); //Removes gold after transaction
	    int getGold(); //Returns gold value as an int

	    Item getItem(int itemIndex); //Returns held item at specified item index
	    void addItem(Item newItem); //Adds a new item into the player's vector
	    void removeItem(int itemIndex); //Removes item from the player's vector
	    void showItems(); //Displays all of the players items to the screen
	    int getNumItems(); //Returns the number of held items as an int
};
