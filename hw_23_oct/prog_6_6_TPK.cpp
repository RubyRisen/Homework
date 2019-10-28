/*
Author: Thomas Kelley
Date: 10/27/2019
Class: COSC 1336
Instructor: Prof Welch
Problem Description: This program asks for the weight of a package and
	the distance it will be shipped. To end the program, enter a weight
	of zero.
*/

#include<iostream> //cin, cout
#include<string> //string
#include<iomanip> //fixed, setprecision()
#include<cmath> //round()
using namespace std;

//function prototypes
float inputProcessing(float numFahrenheit);
float calculateCharge(float numW, float numD);


//main
int main()
{
	string dummyString;
	float numWeight, numDistance, numShippingCharge;

	//intro
	cout << "_______________________________________________________" << endl;
	cout << "| This program asks for the weight of a package and   |" << endl;
	cout << "| the distance it will be shipped. To end the program,|" << endl;
	cout << "| enter a weight of zero.                             |" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "Press enter to continue ";
	getline(cin, dummyString);

	while (true)
	{
		//take input
		cout << "__________________________________________________________" << endl;
		cout << "| Please enter the weight of the package in kilograms:   |" << endl;
		cout << "| (any number greater than zero, which ends the program) |" << endl;
		cout << "----------------------------------------------------------" << endl;
		cin >> numWeight;
		cout << endl;

		//IP call
		numWeight = inputProcessing(numWeight);

		//end program
		if (numWeight == 0)
		{
			break;
		}

		//or take further input
		cout << "____________________________________________________" << endl;
		cout << "| Please enter the distance to be shipped in miles:|" << endl;
		cout << "| (any positive number)                            |" << endl;
		cout << "----------------------------------------------------" << endl;
		cin >> numDistance;
		cout << endl;

		//IP call
		numDistance = inputProcessing(numDistance);

		//call calculation function
		numShippingCharge = calculateCharge(numWeight, numDistance);

		//output
		cout << fixed << setprecision(2);
		cout << "The shipping charge is $" << numShippingCharge << "." << endl << endl;

		//end iteration
		cout << "Press enter to continue ";
		cin.ignore();
		getline(cin, dummyString);
	}

	//end main
	cout << "Thank you!" << endl << endl;
	cout << "Press enter to continue ";
	cin.ignore();
	cin.get();
}

//functions
float inputProcessing(float numInput)
{
	while (numInput < 0)
	{
		cout << "Please enter a positive number or zero: ";
		cin >> numInput;
		cout << endl;
	}
	return numInput;
}

float calculateCharge(float numW, float numD)
{
	float numRate = 3.10;
	float numPerFiveHundred;
	float numResult;

	if (numW > 2.0)
	{
		numRate = 4.20;
	}
	if (numW > 6.0)
	{
		numRate = 5.30;
	}
	if (numW > 10.0)
	{
		numRate = 6.40;
	}

	//finds how many five hundred miles were traveled
	numPerFiveHundred = numD / 500;
	numPerFiveHundred = ceil(numPerFiveHundred);
	numResult = numRate * numPerFiveHundred;

	return numResult;
}
