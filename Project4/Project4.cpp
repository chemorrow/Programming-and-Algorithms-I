/*
 * Project 4
 * Has a minimum of four (4) room objects, each with a name and description.
 * The rooms are connected to create a navigable map.
 * A main menu allows the user to choose directions and navigate between rooms.
 * If the user selects a direction from the currentRoom that is not connected to another room,
 * displays a message.
 * The user's goal is to collect the key from the merchant by selling treasure collected from the rooms.
 * Each room is locked until the user enters the correct pass phrase.
 *
 * Che Morrow
 * Date created: 5/12/2016
 */

#include <iostream>
#include "gameObject.h"
#include "room.h"
#include "player.h"
#include "CinReader.h"
using namespace std;

void clearScreen();

int main ()
{

    //Create a reader object to take in user input.
    CinReader reader;

    //Initialize menu variables and current guess for puzzle doors.
    char menu = 'Q';
    int subMenu = 0;
    int currentGuess = 0;

    //Assigning the puzzles to a string variable for easier passing during construction.
    string puzzleOne = "\nThere is a roll of cloth 1km long. \nA machine cuts it into pieces that are 10m each. \nHow long will it take the machine to cut the roll \nif each cuts takes 4 seconds?";
    string puzzleTwo = "\nA fair maiden is 5 ft, 9 in tall. \nHer shadow was 8 ft long when the trees shadow was 30 ft long. \nTo the nearest foot, how tall is the tree?";
    string puzzleThree = "\nIt takes 1,629 digits to number the pages of a book. \nHow many pages are there?";

    //Constructing all items needed, with name and value.
    Item playerInstructions("Instruction List",0);
    Item merchantKey("Key to the rusty gate", 70);


    Item silverItemOne("Silver Necklace", 5);
    Item silverItemTwo("Silver Plate", 10);
    Item silverItemThree("Silver Ring", 5);
    Item roomTwoItems[3] = {silverItemOne, silverItemTwo, silverItemThree};
    Item goldItemOne("Gold Chalice", 15);
    Item goldItemTwo("Gold Bracelet", 10);
    Item roomThreeItems[2] = {goldItemOne, goldItemTwo};
    Item jewelItemOne("Jeweled Crown", 25);
    Item roomFourItems[1] = {jewelItemOne};

    //Constructing rooms with name, description, puzzle text, puzzle answer, item array, and number of items.
    Room roomOne("Merchant's Shop","The shop keeper is trying not to fall asleep.",puzzleOne,396,0,0);
    Room roomTwo("Silver Puzzle Room","This room contains many small trinkets.",puzzleTwo,22,roomTwoItems,3);
    Room roomThree("Gold Puzzle Room","The gold in this room could buy a country.",puzzleThree,579,roomThreeItems,2);
    Room roomFour("Jeweled Puzzle Room","The light shining off of the jewels almost blinds you.","There are no more puzzles.",0,roomFourItems,1);

    //Use pointers to map out valid paths between rooms.
    roomOne.setNorthRoom(&roomTwo);

    roomTwo.setNorthRoom(&roomThree);
    roomTwo.setSouthRoom(&roomOne);

    roomThree.setNorthRoom(&roomFour);
    roomThree.setSouthRoom(&roomTwo);

    roomFour.setSouthRoom(&roomThree);

    //Create a pointer to hold the current room
    Room* currentRoom = &roomOne;

    //Constructing the main player and a merchant
    Player playerCharacter("Player",0,playerInstructions);
    Player playerMerchant("Merchant Man",70,merchantKey);

    //Do-while loop controls the menu
    do
    {
        clearScreen();
        cout << "You are in the ";

        currentRoom->describe();

        cout << "\nWhere would you like to go? (? for help)" << endl;

        cout << "\nEnter: ";

        menu = reader.readChar();

        //Switch takes in character to select the direction the user wants to travel
        switch (toupper(menu))
        {
        case '?':
            cout << "\n[F] Move your character forward to the next room."
                 << "\n[B] Move your character backward to the previous room."
                 << "\n[U] Try your luck at unraveling the secret to the puzzle door."
                 << "\n[O] Open the locked gate to the outside world."
                 << "\n[V] View items in the room."
                 << "\n[T] Take items from the room."
                 << "\n[S] Sell items to the merchant in the first room."
                 << "\n[P] Purchase the key from the merchant." << endl;
            break;
        case 'F':
            if (currentRoom->getNorthRoom() == 0) //Check if there is a room in the selected direction
            {
                cout << "\nYou can't go that way." << endl;
            }
            else if (currentGuess != currentRoom->getPassphrase())
            {
                cout << "\nA stone puzzle door blocks your way. Perhaps you can solve the puzzle?" << endl;
            }
            else
            {
                currentRoom = currentRoom->getNorthRoom(); //Moves current room to the room in the selected direction
            }
            break;
        case 'B':
            if (currentRoom->getSouthRoom() == 0)//Check if there is a room in the selected direction
            {
                cout << "\nYou can't go that way." << endl;
            }
            else
            {
                currentRoom = currentRoom->getSouthRoom(); //Moves current room to the room in the selected direction
            }
            break;
        case 'O':
            {
                for(int i=0; i<playerCharacter.getNumItems(); i++) //Checking for victory condition
                {
                    if(playerCharacter.getItem(i).getName() == "Key to the rusty gate")
                    {
                        subMenu = 1;
                    }
                    else
                    {
                        subMenu = 0;
                    }
                }
                if(subMenu == 1)
                {
                    cout << "\nYou unlocked the gate to freedom!" << endl;
                    menu = 'Z'; //Victory flag, ends while loop and gives special message
                }
                else
                {
                    cout << "\nYou need to buy the key from the merchant." << endl;
                }
                break;
            }
        case 'U':
            {
                cout << currentRoom->getPuzzleText() << endl;
                currentGuess = reader.readInt();
                if (currentGuess == currentRoom->getPassphrase())
                {
                    cout << "\nYou are correct! The puzzle door slides into the wall." << endl;
                }
                else
                {
                    cout << "\nThat is incorrect. The door remains still." << endl;
                }
                break;
            }
        case 'V':
            {
                cout << "\nWould you like to...? \n1. See your inventory. \n2. View the items in the room. \nChoice: ";
                subMenu = reader.readInt(1,2);
                cout << endl;
                if(subMenu == 1)
                {
                    playerCharacter.showItems();
                    cout << "\nYou have " << playerCharacter.getGold() << " gold." << endl;
                }
                else if(subMenu == 2)
                {
                    if(currentRoom->getNumItems() == 0)
                    {
                        cout << "\nThere are no items in the room." << endl;
                    }
                    else
                    {
                        currentRoom->getRoomItems();
                    }
                }
                break;
            }
        case 'T':
            {
                if(currentRoom->getNumItems() == 0)
                {
                    cout << "\nThere are no more items." << endl;
                }
                else
                {
                    currentRoom->getRoomItems();
                    cout << "\nWhich item would you like to take? \nChoice: ";
                    subMenu = reader.readInt() - 1;
                    cout << endl;
                    playerCharacter.addItem(currentRoom->takeRoomItem(subMenu));
                    currentRoom->removeItem(subMenu);
                }
                break;
            }
        case 'S':
            {
                if(currentRoom->getRoomName() == "Merchant's Shop")
                {
                    cout << "\nChoose an item to sell." << endl;
                    playerCharacter.showItems();
                    subMenu = reader.readInt() - 1;
                    playerMerchant.addItem(playerCharacter.getItem(subMenu));
                    playerCharacter.addGold(playerCharacter.getItem(subMenu).getValue());
                    playerMerchant.removeGold(playerCharacter.getItem(subMenu).getValue());
                    playerCharacter.removeItem(subMenu);
                }
                else
                {
                    cout << "\nYou are in the wrong room. Return to the first room to sell items." << endl;
                }
                break;
            }
        case 'P': //This menu option leads to the purchase screen
            {
                if(currentRoom->getRoomName() == "Merchant's Shop")
                {
                    if(playerCharacter.getGold() == 70)
                    {
                        cout << "\nChoose an item to buy." << endl;
                        playerMerchant.showItems();
                        subMenu = reader.readInt() - 1;
                        playerCharacter.addItem(playerMerchant.getItem(subMenu));
                        playerMerchant.addGold(playerMerchant.getItem(subMenu).getValue());
                        playerCharacter.removeGold(playerMerchant.getItem(subMenu).getValue());
                        playerMerchant.removeItem(subMenu);
                    }
                    else
                    {
                        cout << "\nYou can't afford the key yet. Find me more treasure first!" << endl;
                    }
                }
                else
                {
                    cout << "\nYou are in the wrong room. Return to the first room to sell items." << endl;
                }
                break;
            }
        case 'Z': //This is the victory flag debug. Makes sure that the user cannot cheat out after release.
            {
                cout << "\nNothing happens." << endl;
                menu = 'O';
            }
        }
        cout << "\nPress Enter To Clear Screen"; //Gives user a chance to view screen content before clear
        reader.readString();

    }
    while(toupper(menu) != 'Q' && toupper(menu) != 'Z'); //Quits if the user inputs Q or the victory condition is met

    clearScreen();

    if(toupper(menu) == 'Q') //Displays a message if the quit option is chosen
    {
        cout << "You have exited the game." << endl;
    }
    else if(toupper(menu) == 'Z') //This is the victory message
    {
        cout << "The rusty gate leads to a storm drain. \nAs you crawl into the sunlight, you wonder what will come next." << endl;
    }

    return 0;
}

void clearScreen () { //Uses the clearScreen class to clear the data on the screen
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif // WIN32
}
