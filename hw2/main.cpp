/**
 * Name: Jake Billings
 * Date: 02/03/2018
 * Class: CSCI 2421
 * Description:
 *
 * Task: implement operators for a set using the provided ArrayBag class.
 *
 * Set is implemented as a subclass of ArrayBag. The subclass implements
 *  all operators as describe in the homework (+, -, <<, >>), and overrides
 *  the add() function of ArrayBag so as to prevent the addition of duplicate
 *  integers into a set.
 *
 * My implementation runs ineffciently for sets that contain large integers because
 *  my subclass does not have access to the private items array of ArrayBag. As a result,
 *  it uses hueristics to optimize a guess and check algorithm when testing what
 *  integers are in a set. See implementation functions in Set.cpp.
 *
 * I implement a simple set of unit tests to validate the functionality of my solution.
 *
 * Outline
 * =======
 *  - describe(), assertInt() - Simple Test Suite Functions
 *  - test() Unit Testing
 *  - main(), which includes a call to test() and demo
 *
 * Status: compiles and runs on csegrid
 */

//---------Dependency Imports---------
//Include cout
#include <iostream>
#include <fstream>

//Include the GuessingGame class
#include "Set.h"

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;



//---------Poor Man's Testing Suite----------
/**
 * describe()
 *
 * Used to make the style look similar to mocha javascript tests;
 *  All this function really does is print a string followed by "..."
 *
 * @param expectString A string describing what a test is expecting
 */
void describe(const string expectString) {
    cout << expectString << "...";
}

/**
 * assertInt()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertInt(int expected, int got) {
    if (expected==got) {
        cout << "Passed.";
    } else {
        cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    cout << endl;

    return expected!=got;
}

/**
 * int test()
 *
 * Tests the functionality of the union operators; logs errors to the console if they exist
 */
void test() {
    //Print welcome message
    cout << "========Unit Tests========" << endl;

    //Open an input stream
    ifstream input;
    input.open("setInput.txt");

    //Keep track of how many tests we fail
    unsigned int failCount = 0;


    //Load Set A
    describe("Set A should have 10 elements after loading from setInput.txt");
    Set a;
    input >> a;
    failCount += assertInt(10, a.getCurrentSize());

    //Load Set B
    describe("Set B should have 10 elements after loading from setInput.txt");
    Set b;
    input >> b;
    failCount += assertInt(10, a.getCurrentSize());

    //Test union
    describe("Set A+B (A union B) should have 15 elements");
    Set aUnionB = a + b;
    failCount += assertInt(15, aUnionB.getCurrentSize());

    //Test intersect
    describe("Set A-B (A intersect B) should have 9 elements");
    Set aIntersectB = a - b;
    failCount += assertInt(9, aIntersectB.getCurrentSize());

    //Test set functionality
    describe("Max frequency in all sets should be 1");
    unsigned int maxFreq = 0;
    for (int i = -200; i < 200; i++) {
        if (a.getFrequencyOf(i) > maxFreq) maxFreq=a.getFrequencyOf(i);
        if (b.getFrequencyOf(i) > maxFreq) maxFreq=a.getFrequencyOf(i);
        if (aUnionB.getFrequencyOf(i) > maxFreq) maxFreq=a.getFrequencyOf(i);
        if (aIntersectB.getFrequencyOf(i) > maxFreq) maxFreq=a.getFrequencyOf(i);
    }
    failCount += assertInt(1, maxFreq);

    //Completion message
    cout << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Tests======" << endl;

}

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Run Unit tests
    test();


    //---Demo the application---

    //Load inputs
    ifstream input;
    input.open("setInput.txt");
    Set a;
    Set b;
    input >> a;
    input >> b;

    //Print sets
    cout << "Set A: " << a << endl;
    cout << "Set B: " << b << endl;

    //Calculate union and intersect
    Set aUnionB = a + b;
    Set aIntersectB = a - b;

    //Print union and intersect
    cout << "Set A+B: " << aUnionB << endl;
    cout << "Set B-B: " << aIntersectB << endl;

    //Exit with a 0 status code
    return 0;
}