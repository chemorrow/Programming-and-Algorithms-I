/*
 * Coffee Shop
 * creates a simulation of a coffee shop, using two barista objects each with a line of customer objects.
 *
 * Che Morrow
 * 4/5/16: Date Created
 *
 * 4/21/16: The basic structure of the program is in place. The program passes all test cases assigned.
 *
 * 4/29/16: Program simulation finished. Test cases are commented out at the bottom.
 */

#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "CinReader.h"
#include <iostream>

using namespace std;

/*
 * -Customer Class-
 * Creates a customer object and assigns it attributes. (Time customer arrived, time until order is complete, time until customer leaves.)
 * Class includes a default and overloaded constructor, and setter/getter functions.
 */
class Customer
{
    private:
        string order;
        int arrivalTime;
        int giveUpTime;
        int completionTime;
    public:
        Customer();
        Customer(string newOrder, int newArrivalTime, int timeToServe, int giveUpAfter);
        void setOrder(string newOrder);
        string getOrder();
        int getArrivalTime();
        int getGiveUpTime();
        int getCompletionTime();
};

Customer::Customer(void) //Default Constructor
{
    order = "drip coffee";
    arrivalTime = 0;
    giveUpTime = 0;
    completionTime = 0;
}

Customer::Customer(string newOrder, int newArrivalTime, int timeToServe, int giveUpAfter) //Overloaded Constructor
{
    order = newOrder;
    arrivalTime = newArrivalTime;
    giveUpTime = newArrivalTime + giveUpAfter;
    completionTime = newArrivalTime + timeToServe;
}

void Customer::setOrder(string newOrder) //Give customer an order
{
    order = newOrder;
}

string Customer::getOrder() //Return customers current order
{
    return order;
}

int Customer::getArrivalTime() //Return the customers arrival time
{
    return arrivalTime;
}

int Customer::getGiveUpTime() //Return the customers time until they leave
{
    return giveUpTime;
}

int Customer::getCompletionTime() //Return wait time for drink
{
    return completionTime;
}

/*
 * -Barista Class-
 * Creates a line of customers using an array of object. It's functions manipulate these objects.
 * Class includes default and overloaded constructor, destructor, and setter/getter functions.
 */
class Barista
{
    private:
        int maxCustomers;
        int numCustomers;
        Customer* line;
    public:
        Barista();
        ~Barista();
        Barista(int newMaxCustomers);
        int getNumCustomers();
        int getMaxCustomers();
        void removeCustomer(int customerIndex);
        bool addCustomer(Customer newCustomer);
        Customer getCustomer(int customerIndex);
};

Barista::Barista(void) //Default Constructor
{
    maxCustomers = 10;
    line = new Customer[maxCustomers];
    numCustomers = 0;
}

Barista::Barista(int newMaxCustomers) //Overloaded Constructor
{
    maxCustomers = newMaxCustomers;
    line = new Customer[maxCustomers];
    numCustomers = 0;
}

Barista::~Barista() //Destructor, frees memory associated with the arrays
{
    delete[] line;
}

int Barista::getNumCustomers() //Return number of customers in line
{
    return numCustomers;
}

int Barista::getMaxCustomers() //Return maximum customers allowed in line.
{
    return maxCustomers;
}

void Barista::removeCustomer(int customerIndex) //Remove customer from line
{
    for (int i = customerIndex; i<numCustomers-1; i++)
    {
        line[i] = line[(i+1)];
    }
    numCustomers--;
}

bool Barista::addCustomer(Customer newCustomer) //Add customer to line
{
    if(numCustomers == maxCustomers)
    {
        return false;
    }
    else
    {
        line[numCustomers] = newCustomer;
        numCustomers++;
        return true;
    }
}

Customer Barista::getCustomer(int customerIndex) //Returns customer at specified point in line
{
    return line[customerIndex];
}

int main()
{
    //Initialize Variables
    CinReader reader;
    srand (time(NULL)); //Seeds the random number generator

    int newMaxCustomers = 0;
    int runTime = 0;
    int randNumber = 0;

    int customerLineFull = 0; //Counts number of customers who leave because the lines are full
    int customerLeftLine = 0; //Counts number of customers who gave up due to wait time.
    int customerServed = 0; //Counts number of customers who successfully received their order.

   /*
    * This array holds the statistics for customer types.
    * Index 0: number of "drip coffee" customers who arrived
    * Index 1: number of "specialty coffee" customers who arrived
    * Index 2: number of "coffee and food" customers who arrived
    * Index 3: number of "drip coffee" customers who were successfully serviced
    * Index 4: number of "specialty coffee" customers who who were successfully serviced
    * Index 5: number of "coffee and food" customers who who were successfully serviced
    */
    int customerType [6] = {0,0,0,0,0,0};

    char verbose = 'n'; //Initialize verbose, a 'y' expands the background processes of the program.

    /*
     * Get max customers and total run time
     */

    cout << "How many customers can the first barista handle? : ";
    newMaxCustomers = reader.readInt();
    Barista baristaOne(newMaxCustomers);

    cout << "\nHow many customers can the second barista handle? : ";
    newMaxCustomers = reader.readInt();
    Barista baristaTwo(newMaxCustomers);

    cout << "\nHow much time should pass? : ";
    runTime = reader.readInt();

    cout << "\nDo you want the expanded output? (y/n) : ";
    verbose = reader.readChar();

    /*
     * Starts the clock to run the total run time
     * Deals with arrivals for barista one and two.
     */

    for(int i=0; i<runTime+1; i++)
    {
        if(verbose == 'y')
        {
            cout << "\nMINUTE: " << i << endl;
        }
        //Generates a random number
        randNumber = rand() % 100 + 1;

        //Simulates a 95% chance for a new customer to arrive
        if (randNumber < 95)
        {
            //Generates a new random number
            randNumber = rand() % 100 + 1;

            //Simulates a 50% chance to order drip coffee
            if (randNumber <= 50)
            {
                if(baristaOne.getNumCustomers() != baristaOne.getMaxCustomers())
                {
                    baristaOne.addCustomer(Customer("drip coffee", i, 3, 4));
                    customerType[0]++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "New Customer: Ordered drip coffee from barista one." << endl;
                    }
                }
                else if(baristaTwo.getNumCustomers() != baristaTwo.getMaxCustomers())
                {
                    baristaTwo.addCustomer(Customer("drip coffee", i, 3, 4));
                    customerType[0]++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "New Customer: Ordered drip coffee from barista two." << endl;
                    }
                }
                else
                {
                    customerLineFull++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "Customer Left: Both lines were full." << endl;
                    }
                }
            }

            //Simulates a 35% chance to order specialty coffee
            else if (50 < randNumber && randNumber <= 85)
            {
                if(baristaOne.getNumCustomers() != baristaOne.getMaxCustomers())
                {
                    baristaOne.addCustomer(Customer("specialty coffee", i, 5, 6));
                    customerType[1]++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "New Customer: Ordered specialty coffee from barista one." << endl;
                    }
                }
                else if(baristaTwo.getNumCustomers() != baristaTwo.getMaxCustomers())
                {
                    baristaTwo.addCustomer(Customer("specialty coffee", i, 5, 6));
                    customerType[1]++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "New Customer: Ordered specialty coffee from barista two." << endl;
                    }
                }
                else
                {
                    customerLineFull++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "Customer Left: Both lines were full." << endl;
                    }
                }
            }

            //Simulates a 15% chance to order coffee and food
            else if (85 < randNumber)
            {
                if(baristaOne.getNumCustomers() != baristaOne.getMaxCustomers())
                {
                    baristaOne.addCustomer(Customer("coffee and food", i, 7, 8));
                    customerType[2]++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "New Customer: Ordered coffee and food from barista one." << endl;
                    }
                }
                else if(baristaTwo.getNumCustomers() != baristaTwo.getMaxCustomers())
                {
                    baristaTwo.addCustomer(Customer("coffee and food", i, 7, 8));
                    customerType[2]++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "New Customer: Ordered coffee and food from barista two." << endl;
                    }
                }
                else
                {
                    customerLineFull++;

                    //Displays expanded information if desired
                    if(verbose == 'y')
                    {
                        cout << "Customer Left: Both lines were full." << endl;
                    }
                }
            }
        }
        else
        {
            //Displays expanded information if desired
            if(verbose == 'y')
            {
                cout << "No customers arrived." << endl;
            }
        }

        /*
         * Processing the first customer in each line, making their coffee.
         * Checks to see if the current simulation time has reached the completion time for their order.
         */

        if(baristaOne.getNumCustomers() > 0)
        {
            if(baristaOne.getCustomer(0).getCompletionTime() == i)
            {
                switch(baristaOne.getCustomer(0).getOrder().length()) //This switch determines what the customer ordered and logs it.
                {
                    case 11:
                        customerType[3]++;
                        break;
                    case 16:
                        customerType[4]++;
                        break;
                    case 15:
                        customerType[5]++;
                        break;
                    default:
                        break;
                }
                baristaOne.removeCustomer(0);
                customerServed++;

                if(verbose == 'y')
                {
                    cout << "Customer Served: Barista one finished drink." << endl;
                }
            }
        }

        if(baristaTwo.getNumCustomers() > 0)
        {
            if(baristaTwo.getCustomer(0).getCompletionTime() == i)
            {
                baristaTwo.removeCustomer(0);
                customerServed++;
                if(verbose == 'y')
                {
                    cout << "Customer Served: Barista two finished drink." << endl;
                }
            }
        }


        /*
         * Processing both lines and checking for give up times.
         */

        if(baristaOne.getNumCustomers() > 0)
        {
            for(int u=0; u<baristaOne.getNumCustomers(); u++)
            {
                if(baristaOne.getCustomer(u).getGiveUpTime() == i)
                {
                    if(verbose == 'y')
                    {
                        cout << "Customer Left: Barista one took too long." << endl;
                    }
                    baristaOne.removeCustomer(u);
                    customerLeftLine++;
                }
            }
        }

        if(baristaTwo.getNumCustomers() > 0)
        {
            for(int u=0; u<baristaTwo.getNumCustomers(); u++)
            {
                if(baristaTwo.getCustomer(u).getGiveUpTime() == i)
                {
                    if(verbose == 'y')
                    {
                        cout << "Customer Left: Barista two took too long." << endl;
                    }
                    baristaTwo.removeCustomer(u);
                    customerLeftLine++;
                }
            }
        }
    }

   /*
    * Displays values of customer variables to display an end of simulation report.
    */
    cout << "***************************************" << endl;
    cout << "\nEND OF SIMULATION REPORT:" << endl;
    cout << "Simulation ran for " << runTime << " minutes." << endl;
    cout << "\nCustomers successfully served  : " << customerServed << endl;
    cout << "Customers who left due to line : " << customerLineFull << endl;
    cout << "Customer who gave up in line   : " << customerLeftLine << endl;
    cout << "Customers still waiting in line: " << baristaOne.getNumCustomers() + baristaTwo.getNumCustomers() << endl;

    verbose = 'n';
    cout << "\nReport complete. Display expanded results? (y/n) : ";
    verbose = reader.readChar();

    if(verbose == 'y')
    {
        cout << "\nEXPANDED SIMULATION REPORT:" << endl;
        cout << "\nCustomers who ordered drip coffee          : " << customerType[0] << endl;
        cout << "Customers who ordered specialty coffee     : " << customerType[1] << endl;
        cout << "Customers who ordered coffee and food      : " << customerType[2] << endl;
        cout << "Drip coffee customers who were served      : " << customerType[3] << endl;
        cout << "Specialty coffee customers who were served : " << customerType[4] << endl;
        cout << "Coffee and food customers who were served  : " << customerType[5] << endl;
    }

    return 0;
}

/*
 * CATCH unit tests
 *

 TEST_CASE ("Customer class functionality", "[Customer]") {
 	Customer customerOne;
 	Customer customerTwo("item", 1, 2, 3);

 	CHECK(customerOne.getOrder() == "drip coffee");
 	CHECK(customerOne.getArrivalTime() == 0);
 	CHECK(customerOne.getCompletionTime() == 0);
 	CHECK(customerOne.getGiveUpTime() == 0);

 	customerOne.setOrder("specialty coffee");
 	CHECK(customerOne.getOrder() == "specialty coffee");

 	CHECK(customerTwo.getOrder() == "item");
 	CHECK(customerTwo.getArrivalTime() == 1);
 	CHECK(customerTwo.getCompletionTime() == 3);
 	CHECK(customerTwo.getGiveUpTime() == 4);

 	customerTwo.setOrder("another item");
 	CHECK(customerTwo.getOrder() == "another item");
 }

 TEST_CASE ("Barista class functionality", "[Barista]") {
 	Barista baristaOne;
 	Barista baristaTwo(2);

 	CHECK(baristaOne.getMaxCustomers() == 10);
 	CHECK(baristaOne.getNumCustomers() == 0);

 	CHECK(baristaTwo.getMaxCustomers() == 2);
 	CHECK(baristaTwo.getNumCustomers() == 0);

 	CHECK(baristaTwo.addCustomer(Customer()) == true);
 	CHECK(baristaTwo.getNumCustomers() == 1);
 	CHECK(baristaTwo.addCustomer(Customer("drip coffee", 1, 2, 3)) == true);
 	CHECK(baristaTwo.getNumCustomers() == 2);
 	CHECK(baristaTwo.addCustomer(Customer()) == false);
 	CHECK(baristaTwo.getNumCustomers() == 2);

 	CHECK(baristaTwo.getCustomer(1).getOrder() == "drip coffee");
 	baristaTwo.removeCustomer(0);
 	CHECK(baristaTwo.getNumCustomers() == 1);
 	baristaTwo.removeCustomer(0);
 	CHECK(baristaTwo.getNumCustomers() == 0);
 }*/
