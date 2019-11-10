# Readme for Math Tutor 2

Authors: Thomas Kelley & Brian Eaton

Date: 11/06/2019

Class: COSC 1336

Instructor: Prof Welch

Problem Description: This program prints a menu and gives the user the options of four math equations (+,-,*,/) and an End Program option. Upon selection the user will be given five randomely generated math equations using random integers. (1-12) It will check input for each equation and print one of four random Compliments or Encouragements based on correct or incorrect input. For incorrect input it will print the correct answer. The program will keep track of how many answers of the five were correct, and output this data after the fifth equation. Finally, it will print the global total answers correct, attempted and the percent correct, before looping and asking for a new selction of equations. If end program is selected, the menu for global correct/incorrect will be saved to a file.

## Process

This program has a main function, a Menu function, four Equation functions, (+,-,*,/) Compliment and Encouragement functions (for generating random compliments and encouragements), and a Print To File function that executes on program exit.

The main function enters a loop, and then calls the menu, which returns a selection. It then calls one of Four Equation functions and prints the global score table, or ends the loop and calls the Print To File function.

The functions are:

* A **Menu** function that prints a menu, listing Addition, Subtraction, Multiplication, Division, or Exit

* An **Addition** function, which loops five times, printing a random addition equation each time, calls either the Compliment or Encouragement functions, prints local correct totals, and returns (by reference) the total correct/attempted equations.

* A **Subtraction** function, wich does the exact same thing as the Addition function, just printing Subtraction equations.

* An **Multiplication** function, wich does the exact same thing as the Addition function, just printing Multiplication equations.

* An **Division** function, wich does nearly the same as the rest, in that it asks for both the integer answer and the integer remainder, only returning correct if both are right.

### pseudocode

**Main** Function

	Start the random number generator

	Define a Dummy string for Pause statements
	
	Define ints for Selection, (from the Menu function) Correct answers, (the global number of correct answers) and Total. (the global number of questions that have been answered)

	Define a float variable, Percent, which will hold the global percent of correct answers.

	Do the following While Selection is not equal to five
	
		Call the Menu function, which returns the Selection variable

		Execute Switch statements; which call the equation functions based on Selection. They each pass Correct and Total by reference.
		
		percent is equivalent to the static casts of Correct divided by the static cast of Total, multiplied by onehundred point one.
		
		Print a table list the Correct, Total, and Percent.

		If Selection is not equal to five... (This if statements executes if the program will loop)

			Execute a pause statements

		end if

	End the Do While loop (The program is ready to end)

	Call the Print to file function, which passes Percent, Correct, and Total by value.

	Print a statement saying the totals have been saved to the file.

	Pause the program.	
	
End **main**

Function **Menu** (Prints the menu, takes input)

	Define an integer, Selection.

	Print a Menu With five options.

	Take input to Selection and perform processing (1-5)

	return Selection	
	
End Function

Function **Addition**, which passes two variables by reference

	Define integers, Random A, Random B, and Answer

	Define an integer, Local Correct, and set it to zero.

	Define a string, Response (which will be returned by the Compliment or Encouragements function calls)

	For Loop, to be executed five times

		Start the random number generator, and set Random A and B to a number between 1-12.

		Print an Addition Equation
	
		Take input to Answer

		If Answer is logically equal to Random A + Random B...
		
			Call the Compliment function, which returns to Response.

			Print Response.

			Increment Local Correct and Correct. (by reference)

		End if.

		Else...

			Call the Encouragements Function, which returns to Response.

			Print Response.

			Output Random A + Random B.

		End Else

	End Loop

	Print Local Correct, along with the literal, '5', for the local totals.

end function

Function **Subtraction**, which passes two variables by reference

	Runs EXACTLY the same as the Addition function, only with subtraction used in the equations and logic.
	
end function

Function **Multiplicatiion**, which passes two variables by reference

	Runs the same as the Addition function, only with Multiplication used in the equations and logic.
	
end function

Function **Division**, which passes two variables by reference

	Runs nearly the same as the Addition function. The equation and logic are switched to division, but there is a new variable, Remainder.

	-It asks for the addition input of the remainder, and the logical asks that a correct answers match both the integer divison and modular of the remainder.

	-Otherwise the same.

end function

Function **Compliment**, which returns a string data type

	Defined four constand strings, which are complimentary in nature.

	Run the random number generator.

	Define an integer, Random Compliment, which is asigned to a random number between one and four.

	Execute Switch cases on Random Compliment, which returns a random selection of the four constant strings.

end function

Function **Encouragement**, which returns a string data type

	Executes the same as Compliment, but with encouraging statements rather than compliments.

end function

Function **Print To Screen**, which is passes a float and two integers by value.

	Open the file results.txt

	Prints a menu containing the passed values.

	Close the file.

end Function


## Test Plan

The program should:

1. Continue to add to the total between iterations of the program and iterations of different equation functions.

2. Correctly parse all inputs, adding to the local correct totals, or not, depending on correct answers.

3. Save the table to a file properly.

### Input

T1: Run each of the four equations, checking that the global totals continue to count and be correct, and that the percent correct is correct.

T2: Run each of the four equation functions, answering correctly and incorrectly. Check you're getting correct results and correct totals at the end of each session.

T3: Run the program several times, with different ending states. Check your output file after each, to make sure it matches your end state.

### Output

T1: The total questions should be 20, the total correct should be consistent with your inputs and local totals, as well as matching the percent readout.

T2: All equations should return correct responses, be they Compliments or Encouragements, return the correct answers in the case of wrong input, and output the correct totals at the end of each session.

T3: The output file should be exactly equivalent to the table that prints after the last iteration.

## Things done

11/06/2019

-split coding tasks between us. I took Addition, subtraction, and compliment, Brian took Multiplication, Division, and Encouragement

11/07/2019

-I wrote the code for my half, and fiddled with main() enough to test them. Brian did the same. Met Most of our requirements, and called it a day.

11/08/2019

-I added a Print function that prints the global totals to a file.

-We cleaned up the format of our outputs

-V1.0- Brian addressed issues with the division function, changing it to ask both for the integer answer and remainder

-11/09/2019 

-V1.1- Checked over code one last time. Everything seems in order. We're pretty happy with the results.
