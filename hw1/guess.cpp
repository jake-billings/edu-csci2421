//
// Created by Jake Billings on 1/17/18.
//

#include "guess.h"


/**
 * GuessingGame()
 *
 * @constructor
 *
 * @param min (see min)
 * @param max (see max)
 * @param size (see size)
 */
GuessingGame::GuessingGame(int min, int max, unsigned int size) {
    //Store our instance variables
    this->min = min;
    this->max = max;
    this->size = size;

    //Generate a random secret sequence of length size
    // this is what the user will try to guess
    for (unsigned int i = 0; i < this->size; i++) {
        this->secretNumbers.push_back(rand() % (max - min) + min);
    }
}

/**
 * runGame()
 *
 * Executes the round of guessing game represented by this instance
 *
 * See assignment description for the rules of the game
 */
void GuessingGame::runGame() {
    //Iterate until the game is over
    // The game doesn't terminate until the user correct guesses the secret sequence.
    // We use a break statement to end execution when a correct guess is made
    while (true) {
        //Initialize a vector that stores the guesses a user makes in one round of this game
        vector<int> guesses;

        //Tell the user what they're supposed to enter
        cout << "Enter your guesses for the " << this->size << " integers in the range from " << this->min;
        cout << " to " << this->max << "." << endl;

        //Collect all of the user's guesses
        for (unsigned int i = 0; i < this->size; i++) {
            cout << "> ";
            int guess;
            cin >> guess;
            guesses.push_back(guess);
        }

        //Check how many guesses are correct
        unsigned int correctCount = this->countCorrectGuesses(&guesses);

        //If the user guessed everything correctly, end the game.
        // If the correctCount is the size, the user guessed everything correctly
        if (correctCount >= this->size) {
            cout << "You are correct!";
            break;
        }

        //We know the user wasn't right. Tell them how wrong they were, so they can do
        // better in the next round.
        cout << correctCount << " out of " << this->size << " guesses are correct. Guess again." << endl;
    }
}


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
unsigned int GuessingGame::countCorrectGuesses(vector<int> *guesses) {
    //Copy the guess vector and the secret number vector
    // this is a necessary step because we don't want to count a single guess as
    // multiple correct answers or multiple guesses as correct for a single
    // secret sequence element
    // We will remove elements from these arrays if a correct guess is made.
    vector<int> unusedGuesses(*guesses);
    vector<int> unusedSecretNumbers(this->secretNumbers);

    //Initialize a count of correct guesses
    unsigned int correctGuessCount = 0;

    //Compare every guess to every secret number
    // If there's a match, it's a correct guess.
    //   Increment the count then remove the pair from the storage vectors
    for (int i = 0; i < unusedGuesses.size(); i++) {
        for (int j = 0; j < unusedSecretNumbers.size(); j++) {
            //If the guess matches the number, we found a correct guess
            if (unusedGuesses[i] == unusedSecretNumbers[j]) {
                //Erase the pair to avoid double count
                unusedSecretNumbers.erase(unusedSecretNumbers.begin() + j);
                unusedGuesses.erase(unusedGuesses.begin() + i);

                //Decrement i because we removed an element and i is about to be incremented.
                // We actually need to check the same index again.
                // j doesn't need to be decremented because we're about to break out of this loop.
                i--;
                
                //Increment the guess count; that's the whole point of this
                correctGuessCount++;
                
                //Break; the same guess can't be used twice, so there's no point in checking the rest.
                break;
            }
        }
    }

    return correctGuessCount;
}
