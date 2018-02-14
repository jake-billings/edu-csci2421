/**
 * Name: Jake Billings
 * Date: 02/22/2018
 * Class: CSCI 2421
 * Description:
 *
 * Task: I interpreted the task for this homework as follows:
 *  1. Download MyVector.h
 *  2. Implement MyVector in MyVector.cpp
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
//Include standard libraries we are allowed to use
#include <iostream>
#include <fstream>
#include <vector>

//Include the assignment headers
#include "MyVector.h"

//Use the standard namespace so that we don't have to type "std" all the time
using namespace std;
using namespace HW4;


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
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    cout << endl;

    return expected != got;
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
    input.open("vehiclein.txt");

    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //size
    describe("size: size should startout at zero");
    MyVector v;
    failCount += assertInt(0, v.size());
    describe("size: calling push_back() should increase to size from zero to one");
    v.push_back(0);
    failCount += assertInt(1, v.size());
    describe("size: calling push_back() should increase to size from one to two");
    v.push_back(0);
    failCount += assertInt(2, v.size());
    describe("size: calling pop_back() should decrease to size from two to one");
    v.pop_back();
    failCount += assertInt(1, v.size());
    describe("size: calling pop_back() should decrease to size one to zero");
    v.pop_back();
    failCount += assertInt(0, v.size());

    //empty
    describe("empty: size should startout at zero");
    failCount += assertInt(0, v.size());
    describe("empty: empty should be true since size is zero");
    failCount += assertInt(true, v.empty());
    describe("empty: empty should be false after calling push_back()");
    v.push_back(0);
    failCount += assertInt(false, v.empty());
    describe("empty: empty should be true after calling pop_back()");
    v.pop_back();
    failCount += assertInt(true, v.empty());

    //array: push, pop, [], etc..
    describe("array: size should startout at zero");
    failCount += assertInt(0, v.size());
    describe("array: push_back should place an int at index zero if size is zero");
    v.push_back(7);
    failCount += assertInt(7, v[0]);
    describe("array: push_back should place an int at index one if size is one");
    v.push_back(8);
    failCount += assertInt(8, v[1]);
    describe("array: push_back should place an int at index two if size is two");
    v.push_back(9);
    failCount += assertInt(9, v[2]);
    describe("array: push_back should still have an int at index zero if size is two");
    failCount += assertInt(7, v[0]);
    describe("array: push_back should still have an int at index one if size is two");
    failCount += assertInt(8, v[1]);

    describe("array: attempts to access negative indices should throw errors");
    bool caughtError = false;
    try {
        v[-1];
    } catch (runtime_error e) {
        caughtError = true;
    }
    failCount += assertInt(true, caughtError);
    describe("array: attempts to access barely out of bounds indices should throw errors");
    caughtError = false;
    try {
        v[3];
    } catch (runtime_error e) {
        caughtError = true;
    }
    failCount += assertInt(true, caughtError);
    describe("array: attempts to access very out of bounds indices should throw errors");
    caughtError = false;
    try {
        v[999];
    } catch (runtime_error e) {
        caughtError = true;
    }
    failCount += assertInt(true, caughtError);

    describe("array: pop_back should not affect index zero of an array of size two");
    v.pop_back();
    failCount += assertInt(7, v[0]);
    describe("array: pop_back should not affect index one of an array of size two");
    failCount += assertInt(8, v[1]);
    describe("array: pop_back should not affect index zero of an array of size one");
    v.pop_back();
    failCount += assertInt(7, v[0]);
    describe("array: pop_back should cause calls to zero index to throw errors after being called on array of size one");
    v.pop_back();
    caughtError = false;
    try {
        v[0];
    } catch (runtime_error e) {
        caughtError = true;
    }
    failCount += assertInt(true, caughtError);
    describe("array: pop_back should throw an error when called on array of size 0");
    caughtError = false;
    try {
        v.pop_back();
    } catch (runtime_error e) {
        caughtError = true;
    }
    failCount += assertInt(true, caughtError);
    describe("array: read access operator should work properly for large arrays");
    for (int i = 0; i < 1000; i++) {
        v.push_back(i*2);
    }
    unsigned int readFailCount = 0;
    for (int i = 0; i < 1000; i++) {
        if (v[i] != i*2) readFailCount++;
    }
    failCount += assertInt(0, readFailCount);
    describe("array: pop_back() and empty() should work properly for large arrays");
    for (int i = 0; i < 1000; i++) {
        v.pop_back();
    }
    failCount += assertInt(true, v.empty());

    //search
    describe("search: size should start at zero");
    failCount += assertInt(0, v.size());
    describe("search: search(n) should be -1 on an empty array");
    failCount += assertInt(-1, v.search(8));
    describe("search: search(11) should be 0 when array is [11]");
    v.push_back(11);
    failCount += assertInt(0, v.search(11));
    describe("search: search(11) should be 0 when array is [11, 11]");
    v.push_back(11);
    failCount += assertInt(0, v.search(11));
    describe("search: search(12) should be 0 when array is [11, 11, 12]");
    v.push_back(12);
    failCount += assertInt(2, v.search(12));
    describe("search: search(12) should be -1 after pop_back() when array is [11, 11] again");
    v.pop_back();
    failCount += assertInt(-1, v.search(12));

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
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

    //Print welcome message
    cout << "===========Demo===========" << endl;

    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}