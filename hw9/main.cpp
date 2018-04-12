/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2421
 *
 * Task:
 *  This programming homework is to develop a simple spelling checker. The file dict.txtPreview the document contains
 *  25,021 frequently used words, each on a separate line in lowercase. Read the file, and insert the words into a hash
 *  table with 1373 buckets. Remember to move dict.txt to the csegrid. Then run the command dos2unix dict.dat (to remove
 *  those pesky /r's created by Windows)
 *
 * Outline
 * =======
 *  - describe(), failCount +=  assertInt() - Simple Test Suite Functions
 *  - test() Unit Testing
 *  - main(), which includes a call to test() and demo
 *
 * Status: compiles and runs on csegrid
 */

//---------Dependency Imports---------
//Include standard libraries we are allowed to use
//todo
#include <iostream>
#include <fstream>
#include <vector>

//Include project-specific dependencies
//todo
#include "Dictionary.h"
#include "LinkedList.hpp"
#include "StrUtil.h"

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
 * failCount +=  assertInt()
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
 * failCount +=  assertFloat()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertFloat(float expected, float got) {
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

    describe("StrUtil: toLower(): should leave a lowercase string alone");
    failCount += assertString("asdf123", toLower("asdf123"));
    describe("StrUtil: toLower(): should lowercase an uppercase string");
    failCount += assertString("asdf123", toLower("ASDF123"));

    describe("StrUtil: scrub(): should remove numbers and special chars");
    failCount += assertString("asdf123", scrub("a.s.d.f.1.2.3"));
    describe("StrUtil: scrub(): should remove numbers and special chars AND lowercase uppercase");
    failCount += assertString("adfdafiew", scrub("ADF.DAF.iew"));

    LinkedList<string> list;
    describe("LinkedList: contains(): should return false if called on an empty list");
    failCount += assertInt(false, list.contains("test"));
    describe("LinkedList: contains(): should return true if called on a list that contains an item");
    list.push_front("test");
    failCount += assertInt(true, list.contains("test"));

    Dictionary verySmall;
    describe("Dictionary: should not contain a word that has not been inserted");
    failCount += assertInt(false, verySmall.contains("test"));

    describe("Dictionary: should insert a word and know that it contains that word");
    verySmall.insert("test");
    failCount += assertInt(true, verySmall.contains("test"));

    describe("Dictionary: should not return true if it doesn't contain a word");
    failCount += assertInt(false, verySmall.contains("asdfasdfasdfadsfads"));

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

    Dictionary dict;

    fstream dictIn;
    dictIn.open("dict.txt");

    string word;
    while (dictIn >> word) {
        dict.insert(scrub(word));
    }
    dictIn.close();

    vector<string> misspelledWords;

    fstream in;
    in.open("check.txt");
    unsigned int wordCount = 0;
    unsigned int misspelledCount = 0;
    while (in >> word) {
        wordCount++;
        if (!dict.contains(scrub(word))) {
            misspelledCount++;
            misspelledWords.push_back(word);
        }
    }
    in.close();

    cout << "Words Checked:\t" << wordCount << endl;
    cout << "Words Misspelled:\t " << misspelledCount << endl;

    cout << endl;
    cout << "These are the misspelled words:" << endl;


    for (unsigned int i = 0; i<misspelledWords.size(); i++) {
        cout << misspelledWords[i] << endl;
    }

    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}