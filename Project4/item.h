/*
 * Project 4 : Item Header
 * Declares variables and functions for item class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */
#pragma once

#include "gameobject.h"

#include <iostream>
#include <string>
using namespace std;

/*
 * Item
 * Class derived from GameObject class
 * Has the value of the created item object
 * Has getter for item value
 */

class Item : public GameObject{
	private:
	    int value; //Holds value of the item
	public:
		Item(); //Default constructor
		Item(string newName, int newValue); //Overloaded constructor, takes in name and value

		int getValue(); //Returns value as an integer
};
