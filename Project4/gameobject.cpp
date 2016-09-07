/*
 * Project 4 : GameObject Source
 * Contains functions for GameObject class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */

#include "gameobject.h"

/*
 * GameObject
 * Has a name string
 * Contains setters and getters for name string
 */

GameObject::GameObject ()
: name("GAMEOBJECT") {
}

GameObject::GameObject (string newName)
: name(newName) {
}

void GameObject::setName (string newName) {
	name = newName;
}

string GameObject::getName () {
	return name;
}
