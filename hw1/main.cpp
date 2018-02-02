/**
 * Name: Jake Billings
 * Date: 01/18/2018
 * Class: CSCI 2421
 * Description: Design an ADT for a one-person guessing game that chooses n random
 *  integers in the range from 1 to m and asks the user to guess them. The same integer
 *  might be chosen more than once. For example, the game might choose the following four
 *  integers that range from 1 to 10: 4, 6, 1, 6.
 * Status: compiles and runs on csegrid
 */

//---------Dependency Imports---------
//Include cout
#include <iostream>

//Include the GuessingGame class
#include "guess.h"

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //According to the assignment, Submit ... a main function file main.cpp that asks initial seed number, and prints
    // three sequential numbers generated by the program.

    //Ask an initial seed number
    cout << "Please enter an initial seed number." << endl;
    cout << "> ";
    unsigned int seed;
    cin >> seed;

    //Seed the random number generator
    srand(seed);

    //Print three sequential numbers generated by the program
    for (unsigned int i = 0; i < 3; i++) {
        cout << "Number " << i << ": " << rand() << endl;
    }

    //Collect parameters that we will use for each round.
    // In the homework, these integers all called n and m.
    // In this implementation n is called size and m is called max.
    // min is theoretically configurable, but since the homework
    // specifies a min of 1, we call set a variable min to 1.
    int min = 1;
    cout << "How many integers should be in each sequence you will try to guess?" << endl;
    cout << "> ";
    unsigned int size;
    cin >> size;
    cout << "What is the maximum value an integer in the sequence should be able to have?" << endl;
    cout << "> ";
    int max;
    cin >> max;

    //Validate size, min, and max
    if (max - min <= 0) {
        cout << "Sorry. The maximum value must be greater than " << min << " in order for the game to work." << endl;
        return 1;
    }
    if (size <= 0) {
        cout << "Sorry. The sequences must have at least a length of one for the game to work." << endl;
        return 1;
    }


    //Begin the game loop.
    // We continue to create and run GussingGames until
    // the user doesn't want to anymore.
    while (true) {
        //Initialize a guessing game object. This will store all data for the entire round.
        // this call to constructor generates the random numbers
        GuessingGame g(min, max, size);

        //Run the game
        g.runGame();

        //Ask the user if they'd like to play again. If not, quit.
        cout << "Play again? (Y/N)" << endl;
        cout << "> ";
        char inputContinue;
        cin >> inputContinue;

        // If the user says anything except yes to another round,
        //  quit the game. I don't want to deal with all potential error cases.
        if (inputContinue != 'Y') break;
    }

    //
    return 0;
}