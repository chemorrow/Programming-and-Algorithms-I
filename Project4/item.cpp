/*
 * Project 4 : Item Source
 * Contains functions for Item class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */

#include "item.h"

/*
 * Item
 * Class derived from GameObject class
 *
 *
 */

Item::Item() //Default constructor
: GameObject("UNAMED ITEM"), value(0){
}

Item::Item (string newName, int newValue) //Overloaded constructor, takes in name and value
: GameObject(newName), value(newValue){
}

int Item::getValue(){ //Returns value as an integer
    return value;
}
