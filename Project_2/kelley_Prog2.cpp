#include<iostream>
#include<iomanip>
#include<string>
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
	while(true)
	{
		//ask the user for their selection
		cout << "This program calculates the distance sound travels in a given substance," << endl;
		cout << " (at zero degreees celcius) given the amount of time traveled." << endl << endl;
		cout << "Please enter your selection:" << endl << endl;
		cout << "1. Carbon Dioxide" << endl;
		cout << "2. Air" << endl;
		cout << "3. Helium" << endl;
		cout << "4. Hydrogen" << endl;
		cout << "5. End Program" << endl << endl;

		//input the selection
		cin >> numSelection;
		cout << endl;

		//input validation
		while (numSelection < 1 || numSelection > 5)
		{
			cout << "Input Error. Please enter a number between 1 and 5, inclusive: ";
			cin >> numSelection;
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
		cout << "Please enter the number of seconds it took for the sound to travel through " << textVariable << ": ";
		cin >> numTimeInput;
		cout << endl << endl;

		//process
		numDistance = numTimeInput * numSpeedVar;

		//output
		cout << fixed << setprecision(2);
		cout << "The " << textVariable << " traveled a distance of " << numDistance << " meters." << endl << endl;
		cout << "Press enter to continue ";
		cin.get();
		cin.get();

	//end program loop
	}

	//program ending
	cout << "Thank you. Have a good day." << endl << endl;
	cout << "Press enter to continue ";
	cin.get();
	cin.get();
	return 0;
}
