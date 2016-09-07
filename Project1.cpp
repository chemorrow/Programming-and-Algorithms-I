/*
 * Project 1
 * Implement a basic integer math tutor program.
 *
 * Che Morrow
 * Date created: 2/9/2016
 */

#include "CinReader.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

/*
 * CSCI 20
 * Programming and Algorithms
 *
 * Class MathTutor contains all the integers needed for the project and all functions including:
 * initialize(sets all integers to zero and creates the random seed),
 * setFirstNumber/setSecondNumber(sets the first and second numbers to the generated random value),
 * the rest of the functions perform the stated operation on randomly generated numbers.
 */

class MathTutor
{
    public:
        int firstNumber;
        int secondNumber ;
        int answer;
        int correctResult;
        int correctAnswers;
        int incorrectAnswers;
        int problemsAttempted;
        CinReader reader;

        void initialize()
        {
            srand (time(NULL));
            firstNumber = 0;
            secondNumber = 0;
            answer = 0;
            correctResult = 0;
            correctAnswers = 0;
            incorrectAnswers = 0;
            problemsAttempted = 0;
        }
        void setFirstNumber()
        {
            firstNumber = rand() % 100 + 1;
        }
        void setSecondNumber()
        {
            secondNumber = rand() % 100 + 1;
        }
        void doAddition()
        {
            problemsAttempted++;
            setFirstNumber();
            setSecondNumber();
            cout << endl << firstNumber << " + " << secondNumber << " = " ;
            answer = reader.readInt();
            correctResult = firstNumber + secondNumber;
            if (answer == correctResult)
            {
                cout << "CORRECT!" << endl;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect. Answer was " << correctResult << endl;
                incorrectAnswers++;
            }
        }
        void doSubtraction()
        {
            problemsAttempted++;
            setFirstNumber();
            setSecondNumber();
            cout << firstNumber << " - " << secondNumber << " = ";
            answer = reader.readInt();
            correctResult = firstNumber - secondNumber;
            if (answer == correctResult)
            {
                cout << "CORRECT!" << endl;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect. Answer was " << correctResult << endl;
                incorrectAnswers++;
            }
        }
        void doMultiplication()
        {
            problemsAttempted++;
            setFirstNumber();
            setSecondNumber();
            cout << firstNumber << " * " << secondNumber << " = ";
            answer = reader.readInt();
            correctResult = firstNumber * secondNumber;
            if (answer == correctResult)
            {
                cout << "CORRECT!" << endl;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect. Answer was " << correctResult << endl;
                incorrectAnswers++;
            }
        }
        void doDivision()
        {
            problemsAttempted++;
            setFirstNumber();
            setSecondNumber();
            cout << firstNumber << " / " << secondNumber << " = ";
            answer = reader.readDouble();
            correctResult = firstNumber / secondNumber;
            correctResult = (firstNumber / secondNumber);
            if (answer == correctResult)
            {
                cout << "CORRECT!" << endl;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect. Answer was " << ((firstNumber)) / ((secondNumber)) << endl;
                incorrectAnswers++;
            }
        }
        void doModulo()
        {
            problemsAttempted++;
            setFirstNumber();
            setSecondNumber();
            cout << firstNumber << " % " << secondNumber << " = ";
            answer = reader.readInt();
            correctResult = firstNumber % secondNumber;
            if (answer == correctResult)
            {
                cout << "CORRECT!" << endl;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect. Answer was " << correctResult << endl;
                incorrectAnswers++;
            }
        }
        void describe()
        {
            cout << endl << "CORRECT ANSWERS:\t" << correctAnswers << endl;
            cout << "INCORRECT ANSWERS:\t" << incorrectAnswers << endl;
            cout << "PROBLEMS ATTEMPTED:\t" << problemsAttempted << endl;
            cout << "PERCENTAGE CORRECT:\t" << static_cast<double>(correctAnswers * 100.0 / problemsAttempted)<< "%" << endl;
        }
};

int main ()
{
    MathTutor tutorOne;
    CinReader reader;
    tutorOne.initialize();
    char quit = 'n';

	while (quit == 'n')
    {
        tutorOne.setFirstNumber();
        tutorOne.setSecondNumber();
        tutorOne.doAddition();
        tutorOne.doSubtraction();
        tutorOne.doMultiplication();
        tutorOne.doDivision();
        tutorOne.doModulo();

		cout << endl << "Quit (y/n)? ";
		quit = tolower(reader.readChar("YyNn"));
	}

	tutorOne.describe();

	return 0;

}
