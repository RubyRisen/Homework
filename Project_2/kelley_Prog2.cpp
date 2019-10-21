/*
Author: Thomas Kelley
Date: 10/20/2019
Class: COSC 1336
Instructor: Prof Welch

Problem Description: This program calculates the distance sound travels
	in a gas given the amount of time traveled and the substance
	being traveled through.

Pseudocode/Process: 
variables:

selection variable

Four constant floats that hold the speeds of the 4 gasses.

several floats and one string which will be assigned on the fly after the
	program is selected. This allows me to run a single program that
	executes four different ways.

one string, pause, which I'm using to pause the program between loops.
	This is because I've found cin.get() to be inadequit, as it interacts
	with the input buffer in weird ways. (and we're not using system("pause"))

the program loop:
while true is equal to true, perform the following

	Ask the user for their selection.

	take input into the selection variable

	perform input processing

	if the selection is logically equal to 5, break out of the loop, ending the program.

	execute switch cases. Each case assigns a text variable to the respective gas, 
		and a float to the respective gas's constant.

	ask the user for the time it took to travel through the gas

	take the input and perform processing

	store the result of the gas float times the time input float into the distance variable
		these will be different on each iteration of the program, because of the switch
		cases.

	output the gas and the distance traveled

	pause the system until enter is pressed and the loop restarts

end the loop

end the program

Test Plan:
T1: Assure that the program loops properly and that both input processing loops work.
T2: Assure that each of the 4 programs work correctly.
T3: Assure that the program ends when the selection is equal to 5.

Inputs:
T1: Enter 0 or 6, then -1 or 31. Play through the program with correct input, and
	press enter when prompted at the end.
T2: Run each program (selection 1, 2, 3, and 4) then enter 1 for each distance.
	Go back and enter 2 for program 1.
T3: Enter 5 when prompted to select a program.
Outputs:
T1: For the selection input it should ask you to re-enter. For the time input it should
	do the same. Once correct input has been entered press enter at the end of the program
	and it should loop back to the beggining.
T2: Output should be 258, 331.5, 972, 1270, and then 516. The gas displayed should be
	consitent with the slection.
T3: The program should display a goodbye message, ask you to press enter, and then
	terminate when you do so.
Things done:
10/20/2019
-wrote code. It worked. Sort of. cin.get() didn't seem to work, in either VS or Ubuntu.
	Spent several hours trying to figure it out. cin.get()  doesn't work if there
	are return characters in the buffer. I ran into other problems while trying to
	correct it. For instance, typing text into the prompt adds that text to the
	buffer, creating erounious input on the next loop.

v1.0:
After consulting the internet, I found a solution. Not sure if it's an approved
	solution, but it doesn't involve any extra includes, and works in both
	environments. using cin.ignore() after each input clears the buffer, and
	using getline(cin, variable) allows for a pause that doesn't mess up the
	buffer, and will allow for an empty string to be read to the dummy variable.

*/

#include<iostream> // cin, cout
#include<iomanip> // fixed, setprecision()
#include<string> // string
using namespace std;

int main()
{
	int numSelection;
	const float NUM_CARBON_SPEED = 258;
	const float NUM_AIR_SPEED = 331.5;
	const float NUM_HELIUM_SPEED = 972;
	const float NUM_HYDROGEN_SPEED = 1270;
	//for the program
	float numSpeedVar, numTimeInput, numDistance;
	string textVariable, pause;
	while (true)
	{
		//ask the user for their selection
		cout << "This program calculates the distance sound travels in a substance given the amount of time traveled and the substance being traveled through." << endl << endl;
		cout << "Please enter your selection:" << endl << endl;
		cout << "1. Carbon Dioxide" << endl;
		cout << "2. Air" << endl;
		cout << "3. Helium" << endl;
		cout << "4. Hydrogen" << endl;
		cout << "5. End Program" << endl << endl;

		//input the selection
		cin >> numSelection;
		cin.ignore();
		cout << endl;

		//input validation
		while (numSelection < 1 || numSelection > 5)
		{
			cout << "Input Error. Please enter a number between 1 and 5, inclusive: ";
			cin >> numSelection;
			cin.ignore();
			cout << endl;
		}

		//end program
		if (numSelection == 5)
		{
			break;
		}

		//update the program's variables
		switch (numSelection)
		{
		case 1:	textVariable = "Carbon Dioxide";
			numSpeedVar = NUM_CARBON_SPEED;
			break;
		case 2: textVariable = "Air";
			numSpeedVar = NUM_AIR_SPEED;
			break;
		case 3:	textVariable = "Helium";
			numSpeedVar = NUM_HELIUM_SPEED;
			break;
		case 4:	textVariable = "Hydrogen";
			numSpeedVar = NUM_HYDROGEN_SPEED;
			break;
		default:	numSpeedVar = 0;
			break;
			//end switch
		}

		//the program
		//input
		cout << "Please enter the number of seconds it took for the sound to travel through " << textVariable << ": (0 - 30) ";
		cin >> numTimeInput;
		cin.ignore();

		//input processing
		while (numTimeInput < 0 || numTimeInput > 30)
		{
			cout << "Please enter a number between 0 and 30: ";
			cin >> numTimeInput;
			cin.ignore();
		}
		cout << endl << endl;

		//process
		numDistance = numTimeInput * numSpeedVar;

		//output
		cout << fixed << setprecision(2);
		cout << "The " << textVariable << " traveled a distance of " << numDistance << " meters." << endl << endl;
		
		//end the loop iteration
		cout << "Press enter to continue: ";
		getline(cin, pause);
		cout << endl;

	//end program loop
	}

	//program ending
	cout << "Thank you. Have a good day." << endl << endl;
	cout << "Press enter to continue ";
	cin.get();
	
	return 0;
}
