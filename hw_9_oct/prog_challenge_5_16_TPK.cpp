/*
Author: Thomas Kelley
Date: 10/14/2019
Class: COSC 1336
Instructor: Prof Welch
--
Problem Description: Write a program asking for a rate
	of inflation between 1 and 10%. It will then
	process and output how much $1,000 will be worth
	over the next 10 years.

Process/Pseudocode:
define value as a float with  1,000

take interest rate as a float
process input with a while loop (between 1 and 10)

modify the interest rate buy dividing it by 100, adding 1,
and then dividing  1 by the result;

output the starting value

for counter (1), is less than or equal to 10, iterate counter
	if counter is logically equal to 10, add "and " to the output
		line. This is for output text formatting.

	value equals value times the modifies interest rate
	output the new value and the counter (as the year)
end loop

Test Plan:
Run the program with several different numbers. Test input processing(1),
	make sure the output is correct(2), and test that the math works
	with both integers and floats(3).

Inputs:
Test1: 3
Test2: 0 || 11
Test3: 3.14159

Outputs:
1: 970.87 at the end of year 1 (check)
942.60 at the end of year 2
915.14 at the end of year 3
888.49 at the end of year 4
862.61 at the end of year 5
837.48 at the end of year 6
813.09 at the end of year 7
789.41 at the end of year 8
766.42 at the end of year 9
and 744.09 at the end of year 10

2: Procs input processing  (check)

3: 969.54 at the end of year 1 (check)
940.01 at the end of year 2
911.38 at the end of year 3
883.62 at the end of year 4
856.70 at the end of year 5
830.61 at the end of year 6
805.31 at the end of year 7
780.78 at the end of year 8
757.00 at the end of year 9
and 733.94 at the end of year 10

Things done:
10/24/2019:
-Wrote code. It didn't work! Output numbers were garbled
-tried outputing all numbers each loop
-v1.0:found the problem. I was using 'setprecision()' wrong, without
	the 'fixed' function, causing the output to be limited to
	a precision of 2 instead of a decimal precision of 2.
-V1.1: Added the input processing.
*/

#include<iostream> //cin, cout
#include<iomanip> //fixed, setprecision

using namespace std;

int main()
{
	//variables
	float numInterestRate, numInterestRateModified;
	float numValue = 1000;

	//ask for input
	cout << "Please enter the anual interest rate: (between 1 and 10) ";
	cin >> numInterestRate;

	//input processing
	while (numInterestRate < 1 || numInterestRate > 10)
	{
		cout << endl << "Please enter a number between 1 and 10: ";
		cin >> numInterestRate;
	}

	//modifies input into an easily used format
	numInterestRateModified = 1 / (numInterestRate / 100 + 1);

	//output
	cout << endl << "Given $1,000 today, you would have:" << endl << endl;
	cout << fixed << setprecision(2);

	//loop. Performs math and outputs the total with year counter
	for (int numYear = 1; numYear <= 10; numYear++)
	{
		//output text formatting. adds "and " to the beggining of the final line
		if (numYear == 10)
		{
			cout << "and ";
		}

		//iterative math, Result is modified each loop
		numValue = numInterestRateModified * numValue;

		cout << numValue << " at the end of year " << numYear << endl;
	}

	cout << endl << endl;

	cin.get();
	return 0;
}
