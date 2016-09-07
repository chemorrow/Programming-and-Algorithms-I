/*
 * Project 4 : GameObject Header
 * Declares variables and functions for room class
 *
 * Che Morrow
 * Date created: 5/12/2016
 */

#pragma once

#include <string>
using namespace std;

/*
 * GameObject
 * Declares variables and functions for class
 */

class GameObject {
	private:
		string name;

	public:
		GameObject ();
		GameObject (string newName);

		void setName (string newName);
		string getName ();
};
