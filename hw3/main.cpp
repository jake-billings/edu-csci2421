/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description:
 *
 * Task:
 *
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
#include "Vehicle.h"
#include "functions.h"

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


    //Load Vehicles
    describe("loading: vehicles vector should have 8 elements after loading from vehiclein.txt");
    vector<Vehicle> vehicles;
    Vehicle v;
    while (input >> v) {
        vehicles.push_back(v);
    }
    failCount += assertInt(8, vehicles.size());

    describe("loading: vehicles in vector should have years in which cars were actually manufactured");
    bool invalidYearExists = false;
    for (unsigned int i = 0; i < vehicles.size(); i++) {
        if (vehicles[i].getYear() < 1900 || vehicles[i].getYear() > 2018) invalidYearExists=true;
    }
    failCount += assertInt(0, invalidYearExists);

    describe("loading: vehicles in vector should have valid string makes and models in which cars were actually manufactured");
    bool invalidStrExists = false;
    for (unsigned int i = 0; i < vehicles.size(); i++) {
        if (vehicles[i].getMake().empty() || vehicles[i].getModel().empty()) invalidStrExists=true;
    }
    failCount += assertInt(0, invalidStrExists);


    //Sorting functions
    describe("sorting: sorting vehicles by year should result in a properly ordered ascending list");
    sortByYear(&vehicles);
    bool invalidOrderingExists = false;
    for (unsigned int i = 1; i < vehicles.size(); i++) {
        if (vehicles[i-1].getYear() > vehicles[i].getYear()) invalidOrderingExists=true;
    }
    failCount += assertInt(0, invalidOrderingExists);

    describe("sorting: sorting vehicles by make should result in a properly ordered ascending list");
    sortByMake(&vehicles);
    invalidOrderingExists = false;
    for (unsigned int i = 1; i < vehicles.size(); i++) {
        if (vehicles[i-1].getMake() > vehicles[i].getMake()) invalidOrderingExists=true;
    }
    failCount += assertInt(0, invalidOrderingExists);

    describe("sorting: sorting vehicles by model should result in a properly ordered ascending list");
    sortByModel(&vehicles);
    invalidOrderingExists = false;
    for (unsigned int i = 1; i < vehicles.size(); i++) {
        if (vehicles[i-1].getModel() > vehicles[i].getModel()) invalidOrderingExists=true;
    }
    failCount += assertInt(0, invalidOrderingExists);

    //Recursive Searching
    describe("searching: a recursive binary search by year on a list that is not ordered by year should throw an error");
    sortByMake(&vehicles);
    bool caughtErr = false;
    try {
        binSearchRecYear(&vehicles, 1800);
    } catch (runtime_error e) {
        caughtErr = true;
    }
    failCount += assertInt(1, caughtErr);

    describe("searching: a recursive binary search by year for 1800 should return null");
    sortByYear(&vehicles);
    Vehicle *resultPtr = binSearchRecYear(&vehicles, 1800);
    failCount += assertInt(1, (resultPtr == nullptr));

    describe("searching: a recursive binary search by year for 3000 should return null");
    sortByYear(&vehicles);
    resultPtr = binSearchRecYear(&vehicles, 3000);
    failCount += assertInt(1, (resultPtr == nullptr));

    describe("searching: a recursive binary search by year for 1984 should return null");
    sortByYear(&vehicles);
    resultPtr = binSearchRecYear(&vehicles, 1984);
    failCount += assertInt(1, (resultPtr == nullptr));

    describe("searching: a recursive binary search by year for 1983 should return a non-null DeLorean");
    sortByYear(&vehicles);
    resultPtr = binSearchRecYear(&vehicles, 1983);
    failCount += assertInt(1, (resultPtr != nullptr) && (resultPtr->getMake() == "DeLorean"));

    describe("searching: an recursive binary search by year for 1990 should return a non-null Audi");
    sortByYear(&vehicles);
    resultPtr = binSearchRecYear(&vehicles, 1990);
    failCount += assertInt(1, (resultPtr != nullptr) && (resultPtr->getMake() == "Audi"));

    describe("searching: an recursive binary search should match a slower search for all reasonable values of year");
    sortByYear(&vehicles);
    unsigned int diffCount = 0;
    for (unsigned int i = 1940; i < 2020; i++) {
        if (binSearchRecYear(&vehicles, i) != slowSearchYear(&vehicles, i)) {
            diffCount++;
            cout << "failed at year: " << i;
        }
    }
    failCount += assertInt(0, diffCount);

    //Iterative searching
    describe("searching: an iterative binary search by year on a list that is not ordered by year should throw an error");
    sortByMake(&vehicles);
    caughtErr = false;
    try {
        binSearchIterYear(&vehicles, 1800);
    } catch (runtime_error e) {
        caughtErr = true;
    }
    failCount += assertInt(1, caughtErr);

    describe("searching: an iterative binary search by year for 1800 should return null");
    sortByYear(&vehicles);
    resultPtr = binSearchIterYear(&vehicles, 1800);
    failCount += assertInt(1, (resultPtr == nullptr));

    describe("searching: an iterative binary search by year for 3000 should return null");
    sortByYear(&vehicles);
    resultPtr = binSearchIterYear(&vehicles, 3000);
    failCount += assertInt(1, (resultPtr == nullptr));

    describe("searching: an iterative binary search by year for 1984 should return null");
    sortByYear(&vehicles);
    resultPtr = binSearchIterYear(&vehicles, 1984);
    failCount += assertInt(1, (resultPtr == nullptr));

    describe("searching: an iterative binary search by year for 1983 should return a non-null DeLorean");
    sortByYear(&vehicles);
    resultPtr = binSearchIterYear(&vehicles, 1983);
    failCount += assertInt(1, (resultPtr != nullptr) && (resultPtr->getMake() == "DeLorean"));

    describe("searching: an iterative binary search by year for 1990 should return a non-null Audi");
    sortByYear(&vehicles);
    resultPtr = binSearchIterYear(&vehicles, 1990);
    failCount += assertInt(1, (resultPtr != nullptr) && (resultPtr->getMake() == "Audi"));

    describe("searching: an iterative binary search should match a slower search for all reasonable values of year");
    sortByYear(&vehicles);
    diffCount = 0;
    for (unsigned int i = 1940; i < 2020; i++) {
        if (binSearchIterYear(&vehicles, i) != slowSearchYear(&vehicles, i)) {
            diffCount++;
            cout << endl << "failed at year: " << i;
        }
    }
    failCount += assertInt(0, diffCount);


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

    //Load the standard vehicle list
    cout << "Loading from vehiclein.txt...";
    ifstream input;
    input.open("vehiclein.txt");
    vector<Vehicle> vehicles;
    Vehicle v;
    while (input >> v) {
        vehicles.push_back(v);
    }
    cout << "Done." << endl;

    //Print a welcome message
    cout << "Welcome to the vehicle database. " << vehicles.size() << " vehicles are available." << endl;

    //Acquire user input on what to search for
    cout << "What vehicle year are you interested in?" << endl;
    cout << "> ";
    unsigned int targetYear;
    cin >> targetYear;

    //Perform the search
    cout << "Searching...";
    sortByYear(&vehicles);
    Vehicle *recResultPtr = binSearchRecYear(&vehicles, targetYear);
    Vehicle *iterResultPtr = binSearchIterYear(&vehicles, targetYear);
    cout << "Done." << endl;

    //Print the results
    if (recResultPtr == nullptr) {
        cout << "A recursive binary search did not find a vehicle with that model year." << endl;
    } else {
        cout << "A recursive binary search found the following vehicle: " << endl;
        cout << *recResultPtr << endl;
    }
    if (iterResultPtr == nullptr) {
        cout << "An iterative binary search did not find a vehicle with that model year." << endl;
    } else {
        cout << "An iterative binary search found the following vehicle: " << endl;
        cout << *iterResultPtr << endl;
    }

    //Print exit message
    cout << "Thank you for searching the database. Goodbye." << endl;
    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}