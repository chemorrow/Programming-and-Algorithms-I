/*
 * Work With Strings using the project starter key
 * The purpose of this project is to give you an opportunity to practice using
 * decisions, loops, and C++ strings, and to implement a class that contains
 * accessor and mutator functions.
 *
 * Che Morrow
 * Date created: 3/8/2016
 */

#include "CinReader.h"
#include <cctype> // for character functions
#include <string>
using namespace std;

/*
 * StringWorker
 * Provides utility functions for working with C++ strings.
 */

// StringWorker class goes here
class StringWorker
{
    public:
        string mString;
        void setString(string newString) //Sets the stored string to a user entered string
        {
            mString = newString;
        }
        string getString() //Returns the stored string
        {
            return mString;
        }
        void capitalize() //Converts the first character in the stored string to upper case
        {
             mString[0] = toupper(mString[0]);
        }
        void toUpperCase() //Converts all characters in the stored string to uppercase
        {
            for (unsigned int i=0; i<mString.length(); i++)
            {
                mString[i] = toupper(mString[i]);
            }
        }
        void toLowerCase() //Converts all characters in the stored string to lowercase
        {
            for (unsigned int i=0; i<mString.length(); i++)
            {
                mString[i] = tolower(mString[i]);
            }
        }
        int countAlphabeticCharacters() //Counts all alphabetic characters in the stored string
        {
            int count = 0;
            for (unsigned int i=0; i<mString.length(); i++)
            {
                if (isalpha(mString[i]))
                {
                    count++;
                }
            }
            return count;
        }
        int countNumericCharacters() //Counts all numeric characters in the stored string
        {
            int count = 0;
            for (unsigned int i=0; i<mString.length(); i++)
            {
                if (isdigit(mString[i]))
                {
                    count++;
                }
            }
            return count;
        }
        int countPunctuationCharacters() //Counts all punctuation characters in the stored string
        {
            int count = 0;
            for (unsigned int i=0; i<mString.length(); i++)
            {
                if (ispunct(mString[i]))
                {
                    count++;
                }
            }
            return count;
        }
        bool findWord(string searchWord) //Finds a user entered term in the stored string
        {
            if (mString.find(searchWord) != string::npos)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool replaceWord(string searchWord, string replaceWord) //Finds a user entered term in the stored string and replaces it with another term
        {
            if (mString.find(searchWord) != string::npos)
            {
                size_t found = mString.find(searchWord);
                mString.replace(found,searchWord.length(),replaceWord);
                return true;
            }
            else
            {
                return false;
            }
        }
        void encrypt(int shiftAmount) //Encrypts the string with a Caesar Cipher (ASCII) using a user entered shift
        {
            for (unsigned int i=0; i < mString.length(); i++)
            {
                mString[i] = mString[i] + shiftAmount;
            }
        }
        void decrypt(int shiftAmount) //Encrypts the string with a Caesar Cipher (ASCII) using a user entered shift
        {
            for (unsigned int i=0; i < mString.length(); i++)
            {
                mString[i] = mString[i] - shiftAmount;
            }
        }
};

void clearScreen ();

int main ()
{
	// local variables go here
	CinReader reader;
    StringWorker workerOne;
	int menuChoice = 0;
	string searchWord = "";
	string replaceWord = "";

	do {

        clearScreen();

		// current string and menu go here
		cout << "[1]    Set the string." << endl
             << "[2]    Capitalize the string." << endl
             << "[3]    Convert the string to all uppercase letters." << endl
             << "[4]    Convert the string to all lowercase letters." << endl
             << "[5]    Count the alphabetic characters in the string." << endl
             << "[6]    Count the numeric characters in the string." << endl
             << "[7]    Count the punctuation characters in the string." << endl
             << "[8]    Find a word in the string." << endl
             << "[9]    Replace a word in the string." << endl
             << "[10]   Encrypt the string using the Caesar Cipher algorithm." << endl
             << "[11]   Decrypt the string using the Caesar Cipher algorithm." << endl
             << "[0]    Exit program." << endl;

		// read in menu choice here
        cout << "\nYour selection: ";
		menuChoice = reader.readInt();
		clearScreen();

		// menu switch goes here
		switch(menuChoice)
        {
            case 1:
                cout << "Please enter a string: ";
                workerOne.setString(reader.readString());
                break;
            case 2:
                workerOne.capitalize();
                cout << workerOne.getString() << endl;
                break;
            case 3:
                workerOne.toUpperCase();
                cout << workerOne.getString() << endl;
                break;
            case 4:
                workerOne.toLowerCase();
                cout << workerOne.getString() << endl;
                break;
            case 5:
                cout << workerOne.countAlphabeticCharacters() << " characters" << endl;
                break;
            case 6:
                cout << workerOne.countNumericCharacters() << " numbers" << endl;
                break;
            case 7:
                cout << workerOne.countPunctuationCharacters() << " punctuation" << endl;
                break;
            case 8:
                cout << "Enter the search term: ";
                searchWord = reader.readString();
                if (workerOne.findWord(searchWord) == 1)
                {
                    cout << "Search term located." << endl;
                }
                else
                {
                    cout << "Search term not found." << endl;
                }
                break;
            case 9:
                cout << "Enter your search term: ";
                searchWord = reader.readString();
                if (workerOne.findWord(searchWord) == 1)
                {
                    cout << "Enter your replace term: ";
                    replaceWord = reader.readString();
                    workerOne.replaceWord(searchWord,replaceWord);
                    cout << "New string is: " << workerOne.getString() << endl;
                }
                else
                {
                    cout << "Search term not found." << endl;
                }
                break;
            case 10:
                cout << "Enter the shift amount: ";
                workerOne.encrypt(reader.readInt());
                cout << workerOne.getString() << endl;
                break;
            case 11:
                cout << "Enter the shift amount: ";
                workerOne.decrypt(reader.readInt());
                cout << workerOne.getString() << endl;
                break;
            case 0:
                break;
        }

		if (menuChoice > 0)
        {
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
