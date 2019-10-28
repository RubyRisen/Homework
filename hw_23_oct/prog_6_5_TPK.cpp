/*
Author: Thomas Kelley
Date: 10/27/2019
Class: COSC 1336
Instructor: Prof Welch
Problem Description: This program asks for the sales figure of four
	divisions of a company and outputs the name and figure of the
	company(s) with the highest sales figure.
*/

#include<iostream> //cin, cout
#include<string> //string
#include<iomanip> //fixed, setprecision()
using namespace std;

//function prototypes
double getSales(string division);
void findHighest(double numA, double numB, double numC, double numD);
bool loopProg();

//main
int main()
{
	//variables
	const string DIVISION_A = "Northeast";
	const string DIVISION_B = "Southeast";
	const string DIVISION_C = "Northwest";
	const string DIVISION_D = "Southwest";

	double numTotalA, numTotalB, numTotalC, numTotalD;

	//for looping the program
	bool loopConfirm = 1;
	//dummy variable for "press enter to continue" commands
	string dummyString;
	
	//program intro
	cout << "_______________________________________________________" << endl;
	cout << "| This program asks for the sales figure of four      |" << endl;
	cout << "| divisions of a company and outputs the name and     |" << endl;
	cout << "| figure of the company with the highest sales figure.|" << endl;
	cout << "-------------------------------------------------------" << endl << endl;
	cout << "Press enter to continue ";
		getline(cin, dummyString);

	do
	{
		//sales function calls
		numTotalA = getSales(DIVISION_A);
		numTotalB = getSales(DIVISION_B);
		numTotalC = getSales(DIVISION_C);
		numTotalD = getSales(DIVISION_D);

		//function call includes output
		findHighest(numTotalA, numTotalB, numTotalC, numTotalD);

		//would you like to loop?
		loopConfirm = loopProg();

	} while (loopConfirm == 1);

	//end main
	cout << "Press enter to continue... ";
	cin.get();
}

//functions


double getSales(string division)
{
	//variable
	double numTempVar;

	//take input
	cout << "_____________________________________________________________" << endl;
	cout << "| Please enter the sales figure for the " << division << " division: |" << endl;
	cout << "| (number greater than or equal to zero)                    |" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cin >> numTempVar;
	cout << endl;

	//perform processing
	while (numTempVar < 0)
	{
		cout << "Error: Please enter a number greater than or equal to zero: ";
		cin >> numTempVar;
		cout << endl;
	}

	//return the result
	return numTempVar;
} //end function

//beleive it or not this function is the second least elegant way I found to do this
void findHighest(double numA, double numB, double numC, double numD)
{
	//these flags will become true if their variable is the current highest
	bool flagA = 0;
	bool flagB = 0;
	bool flagC = 0;
	bool flagD = 0;

	bool flagE = 0; //flag for wheather output loop sends output
	bool flagF = 0;	//flag for wheather an "and" statement prints

	//for comparisons
	double comparatorA = -1;
	double comparatorB;

	//for output
	string outputString;
	double outputNumber;

	//this loop sets the flags for each of the four variables
	for (int counterA = 1; counterA <= 4; counterA++)
	{
		//gives the comparator one of the four values
		switch (counterA)
		{
			case 1: comparatorB = numA;
					break;
			case 2:	comparatorB = numB;
					break;
			case 3: comparatorB = numC;
					break;
			case 4: comparatorB = numD;
					break;
		}

		//compares them and sets flags
		if (comparatorB > comparatorA)
		{
			//sets for next loop
			comparatorA = comparatorB;

			//flags
			switch (counterA)
			{
			case 1: flagA = 1;
					flagB = 0;
					flagC = 0;
					flagD = 0;
					break;
			case 2:	flagA = 0;
					flagB = 1;
					flagC = 0;
					flagD = 0;
					break;
			case 3: flagA = 0;
					flagB = 0;
					flagC = 1;
					flagD = 0;
					break;
			case 4: flagA = 0;
					flagB = 0;
					flagC = 0;
					flagD = 1;
					break;
			}
		} //end if

		//checks if the values are the same and sets flags
		else if (comparatorA == comparatorB)
		{
			switch (counterA)
			{
			case 1: flagA = 1;
					break;
			case 2:	flagB = 1;
					break;
			case 3: flagC = 1;
					break;
			case 4: flagD = 1;
					break;
			}
		}//end if
	} //end loop

	//output loop
	for (int counterB = 1; counterB <= 4; counterB++)
	{
		//only outputs if the loop counter causes flag E to be set to 1
		flagE = 0;

		//sets output variables to the respective values
		switch (counterB)
		{
		case 1: if (flagA == 1)
				{
					outputString = "Northeast";
					outputNumber = numA;
					flagE = 1;
				}
				break;

		case 2: if (flagB == 1)
				{
					outputString = "Southeast";
					outputNumber = numB;
					flagE = 1;
				}
				break;
		case 3: if (flagC == 1)
				{
					outputString = "Northwest";
					outputNumber = numC;
					flagE = 1;
				}
				break;
		case 4: if (flagD == 1)
				{
					outputString = "Southwest";
					outputNumber = numD;
					flagE = 1;
				}
				break;
		}

		//output
		if (flagE == 1 && flagF != 1)
		{
			cout << fixed << setprecision(2);
			cout << outputString << " had the most sales at " << outputNumber << endl;
			flagF = 1;
		}
		//for multiple highest
		else if (flagE == 1 && flagF == 1)
		{
			cout << fixed << setprecision(2);
			cout << "and " << outputString << " also had the most sales at " << outputNumber << endl;
		}
	} //end loop
	cout << endl;
} // end function

//asks if the program will loop
bool loopProg()
{
	string yesOrNo;

	while (true)
	{
		cout << "Whould you like to run the program again? (Y/N): ";
		cin >> yesOrNo;
		cin.ignore();
		cout << endl;

		if (yesOrNo == "Yes" || yesOrNo == "yes" || yesOrNo == "y" || yesOrNo == "Y")
		{
			return 1;
		}
		else if (yesOrNo == "No" || yesOrNo == "no" || yesOrNo == "N" || yesOrNo == "n")
		{
			return 0;
		}
		else
		{
			cout << "Please enter Yes or No" << endl;
		}
	}
} //end function
