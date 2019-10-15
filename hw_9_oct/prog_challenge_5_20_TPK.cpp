/*
Author: Thomas Kelley
Date: 10/15/2019
Class: COSC 1336
Instructor: Prof Welch

Problem Description: Write a program that ask for two numbers between
	2 and 10. Print a rectangle of 'x'es of the length and width of
	those numbers, with the lower number as the width.

Process/Pseudocode:
Ask for the two numbers
Peform input processing

if the first number is greater than the second, switch them.
	(using a temporary variable)

for width; is greater than zero; decriment width
	temporary variable is equal to lenght
	for temporary variable; is greater than zero; decriment temp
		print "x"
	end loop
	end line
end loop

Test Plan: Assure that input processing is working properly,(1) that
	the program is running properly,(2) and that the length and width
	is sorting properly.(3)
Inputs:
Test1: 1, 11
Test2: 4, 6
Test3: 6, 4

Outputs:
1: Should ask to resubmit (check)
2: Should print:
xxxxxx (check)
xxxxxx
xxxxxx
xxxxxx
3: Should sort length and width, and print the same as test 2:
xxxxxx (check)
xxxxxx
xxxxxx
xxxxxx

Things done:
10/15/2019
-v1.0: Wrote the code. Thinking through those loops was tricky!
	Program runs, but there was a problem with input processing;
	Would accept incorrect numbers if one of the two was correct.
-v1.1: changed input processing to: (arg || arg) || (arg || arg) format.
*/
#include<iostream> //cin, cout
using namespace std;

int main()
{
	//variables
	int numL, numW, numTemp;

	//input
	cout << "Please enter two whole numbers: (between 2 and 10) " << endl << endl;
	cin >> numL >> numW;
	cout << endl;

	//input processing
	while ((numL < 2 || numL > 10) || (numW < 2 || numW > 10))
	{
		cout << endl << "Error: Please enter two whole numbers between 2 and 10:" << endl << endl;
		cin >> numL >> numW;
	}

	//assures that numA is the lower number, if they are different.
	if (numW < numL)
	{
		numTemp = numL;
		numL = numW;
		numW = numTemp;
	}

	/*
	Output loop. Outer loop counts down length, ending the line on each iteration
		and ending when it reaches zero. Inner loop counts down width, held by
		numTemp, which resets on every loop of the outer loop. Prints a
		single 'x' on each iteration.
	*/
	for (numL; numL > 0; numL--)
	{
		numTemp = numW;
		for (numTemp; numTemp > 0; numTemp--)
		{
			cout << "x";
		}
		cout << endl;
	}

	cout << endl;

	cin.get();
	return 0;
}
