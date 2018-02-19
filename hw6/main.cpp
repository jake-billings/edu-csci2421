/**
 * Name: Jake Billings
 * Date: 03/01/2018
 * Class: CSCI 2421
 *
 * Task:
 *  1. Create a dictionary class
 *    1a. Dictionary class should have a list of type DictEntry
 *    1b. Dictionary class should be able to read all words from a file
 *  2. Implement a main() function
 *    2a. Read A Dictionary object from dictionary.txt
 *    2b. Sort the list in the dictionary class
 *    2c. For each word in findwords.txt,
 *        2c1. search the dictionary for the word
 *        2c2. print the word to the screen along with the number of iterations searches in the dictionary took
 *        2c3. search the dictionary for the word in reverse order
 *        2c2. print the word to the screen along with the number of iterations searches in the dictionary took (reverse)
 *    2d. Print the dictionary words to revsorted.txt in reverse order
 *  3. Extra credit opportunity: Replace the STL List with your own implementation of a doubly linked list
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
#include <sstream>

//Include project header files
#include "SearchResult.h"
#include "DictEntry.h"
#include "Dictionary.h"

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

    //DictEntry
    DictEntry entry;
    describe("DictEntry: should successfully store word");
    entry.setWord("word");
    failCount += assertString("word", entry.getWord());
    describe("DictEntry: should successfully store definition");
    entry.setDef("definition");
    failCount += assertString("definition", entry.getDef());
    describe("DictEntry: comparisions between entries should be alphabetical");
    DictEntry firstPlace;
    firstPlace.setWord("aardvark");
    firstPlace.setDef("dummy");
    failCount += assertInt(false, entry < firstPlace);
    describe("DictEntry: comparisions between entries should be alphabetical (2)");
    DictEntry lastPlace;
    lastPlace.setWord("zzz");
    lastPlace.setDef("dummy");
    failCount += assertInt(false, lastPlace < firstPlace);

    //Dictionary
    ifstream input;
    input.open("dictionary.txt");
    Dictionary dict;
    describe("Dictionary: load: should start with size 0");
    failCount += assertInt(0, dict.getSize());
    describe("Dictionary: load: should successfully load five words from dictionary.txt");
    input >> dict;
    failCount += assertInt(5, dict.getSize());

    Dictionary dict2;
    DictEntry a;
    a.setWord("a");
    DictEntry c;
    c.setWord("c");
    DictEntry b;
    b.setWord("b");
    DictEntry z;
    z.setWord("z");
    DictEntry j;
    j.setWord("j");
    dict2.push_back(a);
    dict2.push_back(c);
    dict2.push_back(b);
    dict2.push_back(z);
    dict2.push_back(j);

    describe("Dictionary: sort: should not start sorted when loading from arbitrary example");
    failCount += assertInt(false, dict2.isSorted());
    describe("Dictionary: sort: should successfully sort arbitrary example");
    dict2.sort();
    failCount += assertInt(true, dict2.isSorted());

    Dictionary dict3;

    describe("Dictionary: search: should return index -1 on empty list");
    failCount += assertInt(-1, dict3.searchByWord("a").getIndex());

    dict3.push_back(a);
    dict3.push_back(c);
    dict3.push_back(b);
    dict3.push_back(z);
    dict3.push_back(j);

    describe("Dictionary: search: should fail on unsorted list");
    bool err = false;
    try {
        dict3.searchByWord("a");
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("Dictionary: search: should not fail on sorted list");
    dict3.sort();
    err = false;
    try {
        dict3.searchByWord("a");
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("Dictionary: search: should proper result index on sorted list for 0th item (a)");
    SearchResult result = dict3.searchByWord("a");
    failCount += assertInt(0, result.getIndex());


    describe("Dictionary: search: should complete search for 0th index on 1st iteration");
    result = dict3.searchByWord("a");
    failCount += assertInt(1, result.getIterations());

    describe("Dictionary: search: should proper result index on sorted list for 4th item (z)");
    result = dict3.searchByWord("z");
    failCount += assertInt(4, result.getIndex());

    describe("Dictionary: search: should complete search for 4th index on 5th iteration");
    result = dict3.searchByWord("z");
    failCount += assertInt(5, result.getIterations());

    describe("Dictionary: search: should index -1 on sorted list for nonexistent item (q)");
    result = dict3.searchByWord("q");
    failCount += assertInt(-1, result.getIndex());
    describe("Dictionary: search: should complete search for nonexistent element on 5th iteration");
    result = dict3.searchByWord("q");
    failCount += assertInt(5, result.getIterations());


    //Reverse
    describe("Dictionary: reverse search: should not fail on reverse sorted list");
    dict3.sort();
    err = false;
    try {
        dict3.searchByWordReverse("a");
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("Dictionary: search: should proper result index on sorted list for 0th item (a)");
    result = dict3.searchByWordReverse("a");
    failCount += assertInt(0, result.getIndex());
    describe("Dictionary: search: should complete search for 0th index on 1st iteration");
    result = dict3.searchByWordReverse("a");
    failCount += assertInt(5, result.getIterations());

    describe("Dictionary: search: should proper result index on sorted list for 4th item (z)");
    result = dict3.searchByWordReverse("z");
    failCount += assertInt(4, result.getIndex());

    describe("Dictionary: search: should complete search for 4th index on 5th iteration");
    result = dict3.searchByWordReverse("z");
    failCount += assertInt(1, result.getIterations());

    describe("Dictionary: search: should index -1 on sorted list for nonexistent item (q)");
    result = dict3.searchByWordReverse("q");
    failCount += assertInt(-1, result.getIndex());
    describe("Dictionary: search: should complete search for nonexistent element on 5th iteration");
    result = dict3.searchByWordReverse("q");
    failCount += assertInt(5, result.getIterations());

    describe("Dictionary: output: dictionary should output \"z\\nj\\nc\\nb\\na\\n\"");
    string line;
    ostringstream os(line);
    os << dict3;
    failCount += assertString("z\nj\nc\nb\na\n", os.str());


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

    //2a. Read A Dictionary object from dictionary.txt
    ifstream input;
    input.open("dictionary.txt");

    Dictionary dict;
    input >> dict;

    //2b. Sort the list in the dictionary class
    dict.sort();

    //2c. For each word in findwords.txt,
    ifstream findinput;
    findinput.open("findwords.txt");

    string word;
    while (getline(findinput, word)) {
        //2c1. search the dictionary for the word
        SearchResult result = dict.searchByWord(word);

        //2c2. print the word to the screen along with the number of iterations searches in the dictionary took
        cout << "Forward search found \"" << word << "\" at index " << result.getIndex() << " in "
             << result.getIterations() << " iterations." << endl;

        //2c3. search the dictionary for the word in reverse order
        SearchResult reverseResult = dict.searchByWordReverse(word);

        //2c2. print the word to the screen along with the number of iterations searches in the dictionary took (reverse)
        cout << "Reverse search found \"" << word << "\" at index " << reverseResult.getIndex() << " in "
             << reverseResult.getIterations() << " iterations." << endl;
    }

    //2d. Print the dictionary words to revsorted.txt in reverse order
    ofstream output;
    output.open("revsorted.txt");
    output << dict;

    //Also print to the console
    cout << "Elements in reverse order:" << endl;
    cout << dict;

    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}