# Readme for programing challenge 6.6

Author: Thomas Kelley

Date: 10/27/2019

Class: COSC 1336

Instructor: Prof Welch

Problem Description: This program asks for the weight of a package and the distance it will be shipped. To end the program, enter a weight of zero.

## Process
This program has a main function and two functions it calls.

The main function outputs an introduction and then runs a while loop. This loop asks for input to a Weight and Distance variables, calls input processing for both, calls the Shipping Charge function, and outputs the shipping charge. The loop has no end condition, but breaks if the weight variable is set to zero.

The functions are:

* An **Input Processing** that assures that inputs are positive numbers or zero.

* A **Calculate Charge** function that calculates based on the weight, Distance, and Rate what the price will be. It then returns this value.

### pseudocode

**Main** Function

	define a String variable for taking input after "Press enter to continue" statements.

	Define Floats for Distance, Weight, and Shipping Charge

	Print the program introduction and ask the user to press enter to continue.

	_While_ true is equal to true

		Ask for input in package weight. Take input to the Weight variable

		Call the Input processing function, which will take and return the Weight.

		if Weight is logically equal to zero

			break out of the loop, ending the program

		end if

		Ask for input in distance. Take input to the Distance variable.

		Call the Input processing function, which will take and return the Distance.

		Call the Calculate Charge Function, which will take the Weight and Distance, and return to the Shipping Charge Variable

		Output the Shipping Charge.

		ask the user to press enter and end this iteration of the loop

	End _Loop_

	Print a goodbye message and ask the user to press enter to end the program

End **main**

Function **Input Processing** takes a float value, Input

	_While_ input is less than zero

		ask the user to input a positive number or zero.

	end _loop_

	return Input

End Function

Function **Calculate Charge** takes two float values, W and D.

	define a Float, Rate. Set it to 3.10 (The lowest rate)

	define a Float, Per Five Hundred (Will count the number of times the rate is charged)

	Define a float, Results, which will return the results.

	(These if statements set the Rate)

	if W(eight) is greater than 2

		Rate is equal to 4.20

	end if

	if Weight is greater than 6

		Rate is equal to 5.30

	end if

	if Weight is greater than 10

		Rate is equal to 6.40

	end if

	(These statements count the number of times Distance passes 500, adding 1 to the variable Per Five Hundred each time)

	 Variable Per Five Hundred is equal to Distance divided by five hundred.

	 Variable Per Five Hundred is equal to  itself, rounded up to the next whole number if it's not already.

	 Result is equal to Rate multiplied by the Variable Per Five Hundred.

	 Return Result

End Function

## Test Plan

The program should:

1. End properly when a Weight of zero is entered

2. It should charge the same price between a weight of 0.1 and 1.9, combined with a Distance of 1 or 499.

3. It should properly count the Distance counter when it goes above 500 and change the rate as Weight goes up.

### Input

T1: Enter a Weight of Zero

T2: On Successive iteration of the program enter 1 and 2 for Weight, and 1 and 499 for Distance.

T3: On Successive iterations of the program enter 3 and 11 for Weight, and 501 and 1001 for Distance.

### Output

T1: Program should end.

T2: Output should be the same for both iterations, $3.10.

T3: Out put should be $8.40 (rate of 4.20 times 2) and $19.20. (rate of 6.40 * 3)

## Things done

10/27/2019

v1.0:-wrote code.
