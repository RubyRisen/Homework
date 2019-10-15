/*
Author: Thomas Kelley
Date: 10/15/2019
Class: COSC 1336
Instructor: Prof Welch

Problem Description: Write a program which asks for the selection
	of several different mathematic programs, generates an equation
	and confirms if the input is correct. The program will loop until
	ended by the user.

Pseudocode:
define variables for the two random numbers, the user guess, and
	the correct answer.

start the random number generator
define a selection variable

do while selection is not equal to 4
	Ask for a selection between Addition(1), Subtraction(2),
		Multiplication(3), and End Program(4)
	take input into selection
	while selection is less than one or greater than 4, ask for input again.

	switch selection
		Case1: Perform addition
		Case2: Perform Subtraction
		Case3: Perform Multiplication
		Default: break
		(Each program Generates two random numbers, outputs an equation, asks
			for input, and checks input with an If/else statement. The same
			variables will be used again if the user makes a different selection,
			just with a different math equation and new random numbers)

end loop (The loop will end without a program displayed if 4 is selected)

print a 'thank you' statement and end the program.

Test Plan: I need to check that the program loops, changes the random numbers
	with each iteration, and continues to loop until 4 is selected. I also
	need to check that the three programs accept correct and rejects 
	incorrect input.

Inputs:
Test 1: Play through the program multiple times. Input 0, 5, 1, 2, and 3.
	After running several programs, enter 4.
Test 2: Input correct answer in programs 1, 2, and 3.
Test 3: Input incorrect answer in porgrams 1, 2, and 3.

Outputs:
Test1: Should reject numbers besides 1-4, and continue until (check)
	you enter 4. 
Test2: Programs should display that answer was Correct. (check)
Test3: Program should tell you that answer was incorrect, and display (check)
	the correct one. 

Things done:
10/15/2019:
-v1.0: Wrote Code: Decided on a Do-While loop with a nested switch statement.
-v1.1: Spent a lot of time altering the formatting for ease of reading durring
	playback and iteration. Works good.
*/

#include <iostream> // cin, cout
#include <iomanip> // setw()
#include <cstdlib> //rand()
#include <ctime> //srand, time

using namespace std;

int main()
{
	//variables. Used in all programs
	int randNumA, randNumB, numGuess, numTotal;
	numGuess = 0;

	//random number generator
	srand(time(0));
	
	int numSelection;
	//master loop. Iterates until numSelection = 4
	do
	{
		//select a program to run
		cout << endl << "Please select from the following by entering a (whole) number." << endl;
		cout << "1. An Addition Problem" << endl;
		cout << "2. A Subtraction Problem" << endl;
		cout << "3. A multiplication Problem" << endl;
		cout << "4. End the Program" << endl << endl;
		cin >> numSelection;

		//input processing
		while (numSelection < 1 || numSelection > 4)
		{
			cout << endl << "Error: Please enter a whole number between 1 and 4: ";
			cin >> numSelection;
		}

		//the programs
		switch (numSelection)
		{
		case 1:	// Addition
				randNumA = rand() % 41 + 10;
				randNumB = rand() % 41 + 10;

				//writes equation
				cout <<  endl << setw(4) << randNumA << endl;
				cout << "+ " << randNumB << " = " << endl;
				cout << "----" << endl << endl;

				//input
				cin >> numGuess;

				//process
				numTotal = randNumA + randNumB;
				if (numGuess == numTotal)
				{
					cout << endl << "Correct!" << endl << endl;
				}
				else
				{
					cout << endl << "Sorry, the correct answer was " << numTotal << endl;
				}

				break;

		case 2:	//Subtraction
				randNumA = rand() % 41 + 10;
				randNumB = rand() % 41 + 10;

				//writes equation
				cout << endl << setw(4) << randNumA << endl;
				cout << "- " << randNumB << " = " << endl;
				cout << "----" << endl;

				//input
				cin >> numGuess;

				//process
				numTotal = randNumA - randNumB;
				if (numGuess == numTotal)
				{
					cout << endl << "Correct!" << endl << endl;
				}
				else
				{
					cout << endl << "Sorry, the correct answer was " << numTotal << endl << endl;
				}

				break;

		case 3:	//Multiplication
				randNumA = rand() % 41 + 10;
				randNumB = rand() % 41 + 10;

				//writes equation
				cout << endl << setw(4) << randNumA << endl;
				cout << "* " << randNumB << " = " << endl;
				cout << "----" << endl;

				//input
				cin >> numGuess;

				//process
				numTotal = randNumA * randNumB;
				if (numGuess == numTotal)
				{
					cout << endl << "Correct!" << endl << endl;
				}
				else
				{
					cout << endl << "Sorry, the correct answer was " << numTotal << endl << endl;
				}

				break;

		default:	break;
		}
	} while (numSelection != 4);


	cout << endl << "Thanks, have a good day!" << endl << endl;

	cin.get();
	return 0;
}
