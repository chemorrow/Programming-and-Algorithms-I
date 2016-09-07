/*
 * Project 4 : Player Source
 * Contains functions for player class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */

#include "player.h"

/*
 * Player
 * Class derived from GameObject class
 * Has gold values and vector for each player
 * Has setter/getters for gold and vectors
 */

Player::Player() //Default constructor
: GameObject("UNAMED PLAYER"), gold(0){
}

Player::Player(string newName, int newGold, Item newItem) //Overloaded constructor, passed name, gold and starting item.
: GameObject(newName), gold(newGold){
    playerItems.push_back(newItem);
}

void Player::showItems(){ //Displays all of the players items to the screen
    for(int i=0; i<playerItems.size(); i++)
    {
        cout << i+1 << ". " << playerItems[i].getName() << endl;
    }
}

Item Player::getItem(int itemIndex){ //Returns held item at specified item index
    return playerItems[itemIndex];
}

void Player::addItem(Item newItem){ //Adds a new item into the player's vector
    playerItems.push_back(newItem);
}

void Player::removeItem(int itemIndex){ //Removes item from the player's vector
    playerItems.erase(playerItems.begin()+itemIndex);
}

int Player::getGold(){ //Returns gold value as an int
    return gold;
}

void Player::addGold(int newGold){ //Adds gold after transaction
    gold += newGold;
}

void Player::removeGold(int newGold){ //Removes gold after transaction
    gold -= newGold;
}

int Player::getNumItems(){ //Returns the number of held items as an int
    return playerItems.size();
}

