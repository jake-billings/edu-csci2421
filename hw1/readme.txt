*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     :  CSC 2421           
*  Due Date  :  Feb. 1, 2018
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program hw1 implements the game described in the homework problem.

"Design an ADT for a one-person guessing game that chooses n random
  integers in the range from 1 to m and asks the user to guess them. The same integer
  might be chosen more than once. For example, the game might choose the following four
  integers that range from 1 to 10: 4, 6, 1, 6."

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   main() maintains the UI loop. It initializes game rounds and asks
   the user when it's time to quit. It instantiates one GuessingGame
   per round.


Name:  guess.h
   Contains the definition for the class GuessingGame.

Name: matrix.cpp
   Defines and implements the GuessingGame class for executing
   one game. The class stores secret numbers and executes
   rounds of guessing to find the secret sequence of numbers.
   The constructor generates the random numbers.
   
   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.

