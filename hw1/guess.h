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
#ifndef EDU_CSCI2421_GUESSINGGAME_H
#define EDU_CSCI2421_GUESSINGGAME_H

//Include the libraries vector, random, and iostream
#include <vector>
#include <random>
#include <iostream>

//Use the standard namespace
using namespace std;

/**
 * GuessingGame
 *
 * ADT for one round of the guessing game described for this assignment.
 *
 * See description
 */
class GuessingGame {

private:
    /**
     * min
     *
     * the minimum value that could appear in a secret sequence
     */
    int min;

    /**
     * max
     *
     * the maximum value that could appear in a secret sequence
     */
    int max;

    /**
     * size
     *
     * the length of the secret sequence that the user is trying to guess
     */
    unsigned int size;

    /**
     * secretNumbers
     *
     * the secret sequence that users are trying to guess in the guessing game
     *  initialized in constructor via random generation
     */
    vector<int> secretNumbers;

public:
    /**
     * GuessingGame()
     *
     * @constructor
     *
     * @param min (see min)
     * @param max (see max)
     * @param size (see size)
     */
    GuessingGame(int min, int max, unsigned int size);

    /**
     * runGame()
     *
     * Executes the round of guessing game represented by this instance
     *
     * See assignment description for the rules of the game
     */
    void runGame();

    /**
     * countCorrectGuesses()
     *
     * helper function to check how many correct guesses are contained in a vector
     *
     * According to the assignment, order doesn't matter. Consider the following sequence:
     * {3, 1, 2, 3}
     *
     * The following guess sequences have the following results:
     * {1, 2, 3, 4} -> 3
     * {3, 1, 2, 3} -> 4
     * {3, 3, 1, 2} -> 4
     * {1, 1, 1, 1} -> 1
     *
     * @param guesses a pointer to a vector containing the guesses that we would like to compare to our secret sequence
     * @return the number of elements in *guesses that can be considered correct guesses w.r.t our secret sequence
     */
    unsigned int countCorrectGuesses(vector<int> *guesses);
};


#endif //EDU_CSCI2421_GUESSINGGAME_H