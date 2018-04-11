/**
 * ======================== Update =========================
 * This implementation is locked by project requirements
 * to use a pre-written header file. This header file
 * contains a full Node object as the head instead of
 * just a head pointer. It also doesn't use generic typing.
 * A better LinkedList example is available at this link:
 *
 * https://github.com/jake-billings/edu-csci2312/tree/master/hw06
 *
 * Name: Jake Billings
 * Date: 03/01/2018
 * Class: CSCI 2421
 *
 * Task:
 *  1. Implement LinkedList in a cpp file based on LinkList.h
 *  2. Verify the functionality of LinkedList in main.cpp
 *  3. Analyze the asyptotic complexity of the following functions:
 *    a. insertAtFront()
 *    b. insertAtBack()
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
//Include sstream for testing the output of the << operator
#include <sstream>

//Include the assignment headers
#include "LinkedList.h"

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
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    cout << endl;

    return expected != got;
}

/**
 * assertString()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertString(string expected, string got) {
    if (expected == got) {
        cout << "Passed.";
    } else {
        cout << "Failed. Expected \"" << expected << "\"; Got \"" << got << "\".";
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

    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //insertAtFront
    describe("insertAtFront: should successfully store char at pos zero with length 0");
    LinkedList v;
    failCount += assertInt(true, v.insertAtFront('f'));
    describe("insertAtFront: should successfully store char at pos zero with length 1");
    failCount += assertInt(true, v.insertAtFront('d'));
    describe("insertAtFront: should successfully store char at pos zero with length 2");
    failCount += assertInt(true, v.insertAtFront('s'));
    describe("insertAtFront: should successfully store char at pos zero with length 3");
    failCount += assertInt(true, v.insertAtFront('a'));
    describe("insertAtFront: list should contain \"asdf\"");
    string line;
    ostringstream os(line);
    os << &v;
    failCount += assertString("asdf", os.str());

    //insertBeforePosition
    describe("insertBeforePosition: should successfully store char at pos zero with length 4 using insertBeforePosition('q',0)");
    failCount += assertInt(true, v.insertBeforePosition('q', 0));
    describe("insertBeforePosition: list should now contain \"qasdf\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qasdf", os.str());
    describe("insertBeforePosition: should successfully store char at pos two with length 5 using insertBeforePosition('w',2)");
    failCount += assertInt(true, v.insertBeforePosition('w', 2));
    describe("insertBeforePosition: list should now contain \"qawsdf\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawsdf", os.str());
    describe("insertBeforePosition: should successfully store char at second to last pos with length 6 using insertBeforePosition('e',5)");
    failCount += assertInt(true, v.insertBeforePosition('e', 5));
    describe("insertBeforePosition: list should now contain \"qawsdef\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawsdef", os.str());
    describe("insertBeforePosition: should successfully store char at last pos with length 7 using insertBeforePosition('r',7)");
    failCount += assertInt(true, v.insertBeforePosition('r', 7));
    describe("insertBeforePosition: list should now contain \"qawsdefr\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawsdefr", os.str());

    //insertAtBack
    describe("insertAtBack: should successfully store char at back of linked list");
    failCount += assertInt(true, v.insertAtBack('t'));
    describe("insertAtBack: list should now contain \"qawsdefrt\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawsdefrt", os.str());
    describe("insertAtBack: should successfully store char at back of linked list");
    failCount += assertInt(true, v.insertAtBack('y'));
    describe("insertAtBack: list should now contain \"qawsdefrty\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawsdefrty", os.str());

    //deleteAtBack
    describe("deleteAtBack: should successfully delete char at back of linked list");
    failCount += assertInt(true, v.deleteAtBack());
    describe("deleteAtBack: list should now contain \"qawsdefrt\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawsdefrt", os.str());

    //deletePosition
    describe("deletePosition: should successfully delete char in middle of linked list");
    failCount += assertInt(true, v.deletePosition(3));
    describe("deletePosition: list should now contain \"qawdefrt\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("qawdefrt", os.str());
    describe("deletePosition: should successfully delete char at front of linked list");
    failCount += assertInt(true, v.deletePosition(0));
    describe("deletePosition: list should now contain \"awdefrt\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("awdefrt", os.str());
    describe("deletePosition: should successfully delete char at end of linked list");
    failCount += assertInt(true, v.deletePosition(7));
    describe("deletePosition: list should now contain \"awdefr\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("awdefr", os.str());

    //deleteAtFront
    describe("deleteAtFront: should successfully delete char at front of linked list");
    failCount += assertInt(true, v.deleteAtFront());
    describe("deleteAtFront: list should now contain \"wdefr\"");
    line.clear();
    os = ostringstream(line);
    os << &v;
    failCount += assertString("wdefr", os.str());

    //test for small arrays
    LinkedList a;
    describe("deleteAtBack: should return false if the list is empty");
    failCount += assertInt(false, a.deleteAtBack());
    describe("deleteAtBack: should return true if the list is one item");
    a.insertAtFront('a');
    failCount += assertInt(true, a.deleteAtBack());
    describe("deleteAtBack: should return false if the list has been emptied");
    failCount += assertInt(false, a.deleteAtBack());

    LinkedList b;
    describe("deletePosition: should return false if the list is empty at 0");
    failCount += assertInt(false, b.deletePosition(0));
    describe("deletePosition: should return false if the list is empty at 5");
    failCount += assertInt(false, b.deletePosition(5));
    describe("deletePosition: should return false if the list is one item and a delete call is made for index 5");
    b.insertAtFront('a');
    failCount += assertInt(false, b.deletePosition(5));
    describe("deletePosition: should return true if the list is one item and a delete call is made for index 0");
    failCount += assertInt(true, b.deletePosition(0));
    describe("deletePosition: should return false if the list has been emptied");
    failCount += assertInt(false, b.deletePosition(0));

    LinkedList c;
    describe("deleteAtFront: should return false if the list is empty");
    failCount += assertInt(false, c.deleteAtFront());
    describe("deleteAtFront: should return true if there is an item in the list");
    c.insertAtFront('a');
    failCount += assertInt(true, c.deleteAtFront());
    describe("deleteAtFront: should return false if the list has been emptied");
    failCount += assertInt(false, c.deleteAtFront());


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