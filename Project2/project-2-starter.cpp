/* PROJECT 2 STARTER KEY */
/* ADD APPROPRIATE DOCUMENTATION HERE */

#include "CinReader.h"
#include <cctype> // for character functions
#include <string>
using namespace std;

// StringWorker class goes here

void clearScreen ();

int main () {
	// local variables go here
	
	do {
		clearScreen();
		// current string and menu go here

		// read in menu choice here

		clearScreen();
		
		// menu switch goes here
		
		if (menuChoice > 0) {
			cout << endl << "Press ENTER to continue";
			reader.readString();
		}
	} while (menuChoice != 0);

	return 0;
}

void clearScreen () {
#if defined(_WIN32) || defined(_WIN32)
	system("cls");
#else
	system("clear");
#endif	
}
