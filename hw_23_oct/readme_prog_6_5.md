# Readme for programing challenge 6.5

Author: Thomas Kelley

Date: 10/27/2019

Class: COSC 1336

Instructor: Prof Welch

Problem Description: This program calculates the distance sound travels in a gas given the amount of time traveled and the substance being traveled through.

## Process
This program has a main function and three others which it calls.

The main function outputs an introduction and then runs a do-while loop which calls functions and will only end when the loop function returns 1.

The three functions are:

* A **Get Sales** function that asks for sales figures and performs input processing.

* A **Find Highest** function that assesses which of the four inputs is the highest, keeps track in it's logic if multiple ones are the highest, and outputs the highest sale or sales with the division name or names.

* A **Loop Program** function, which asks if the user will loop the program.

### pseudocode

**Main** Function

	Define four string constants and give them the names of the divisions

	Define four Double variables for the Total Sales of each division

	Define a Boolean variable for confirming the loop of the program and set it to 1.

	Define a String variable for taking input after "Press enter to continue" statements.

	Print the program introduction and ask the user to press enter to continue.

	_Do_ the following _While_ the loop variable is logically equal to 1.

		Call the Get Sales function four times, passing the Division strings to each, respective. The Total Sales variables will take the returning result.

		Call the Find Highest function, passing the four Total Sales variables to it

		Call the Loop Program function, which returns to the Loop variable.

	End _Loop_

	Print a goodbye message and ask the user to press enter to end the program

End **main**

Function **Get Sales**

	Define a Temporary Double variable

	Ask for a number greater than or equal to zero, and take input to the Temporary variable.

	While the Temporary variable is less than zero, perform input processing

	Return the Temporary variable.

End Function

Function **Find Highest** takes four Double values A through D.

	define Boolean flags A through F.

	Define Double Comparators A and B. Be is set to -1.

	For the Output loop define and Double and a String.

	A _For Loop_ defines a counter that will cause 4 loops

		Switch statements 1 through 4 will give Counter A the value of each of the four totals on the respective loops.

		if Comparator B is greater than Comparator A

			Comparator A takes Comparator B's value.

			Depending on which loop we are in, Switch Statements will then set the respective flags A through D to 1 and set the rest to zero.

			(This clears previously set flags on other loop iterations)
		End if

		if Comparator A is logically equal to Comparator B

			Depending on which loop we're in, switch statements will set the respective flags A through D to 1.

			(importantly this will NOT zero out other flags)
		end if
	end _loop_

	A _For Loop_ that will run four times

		set flag E to 0

		(output will only be printed if this flag is changed to 1)

		Switch cases execute. Each of the four loops will run a different if statement.

			if the loops respective flag is set to 1

				Then flag E is set to one, and the output variables are set to the respective values.

		If flag E is set to 1 and flag F is not

			output the Output variables.

			set flag F to 1

		end if

		Else if Flag E and F are set to one

			output the Output variables, formatting the text to indicate that more than one value is the highest.

			(This if statement only runs if the other output statement has already run on a previous loop. Therefor it will only run if more than one value is highest)
		end if

	end _loop_

end function

Function **Loop Program**
	
	Define a String variable for Yes or No

	while true is equal to true

		Ask the user if they would like to run the program again and take input into the Yes or No variable.

		If the Yes or No variable is equal to Y, y, Yes, or Yes
			return 1

		end if
		if the Yes or No variable is equal to N, n, No, or no
			return 0
		end if

		else
			ask the user to enter Yes or no
		end else

	End loop.

	(This loop will end by default when a return statement is encountered.)

End Function


## Test Plan

The program should:
1. End properly when the Loop function gets the input N or No.

2. It should properly take in the input and process it through the Get Sales function.

3. It should properly sort the four division sales and output ALL of the highest sales and divisions.

### Input

T1: Run through the program once and try entering No to the loop function 

T2: Write code into the findHighest function that outputs all four values. Run it with 1, 1, 1, and 1.

T3: Test the Find Highest function by entering:
	* 1, 1, 1, 1
	* 2, 1, 1, 1
	* 1, 2, 1, 1
	* 1, 1, 2, 1
	* 1, 1, 1, 2
	* 1, 2, 2, 1

### Output

T1: Program should end

T2: Output should be 1, 1, 1, and 1. Delete this code.

T3: The first should return all four as highest. The others should return the respective names and values, with the last returning the second and third.

## Things done
10/27/2019

v1.0:-wrote code. It's the least elegant solution I've come up with so far in this class. I think I've probably been overthinking it. The findHighest function is quite a thing. Any tips on how I could have made it less stupid?

