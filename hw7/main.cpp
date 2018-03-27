/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 *
 * Task: Implement an event-based simulation of a bank line as described in the homework problem
 *  customer arrivals are represented by CustomerEvent where the type is "ARRIVAL"
 *  these arrivals imply departures
 *  departures can only occur after a customer has waited in line then processed a transaction
 *   at the head of the line
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
#include <iostream>
#include <fstream>
#include <queue>

//Include project-specific dependencies
#include "Simulation.h"
#include "SimulationResult.h"
#include "CustomerEvent.h"

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

    //Test the CustomerEvent object and it's >> operator
    ifstream in;
    in.open("input.txt");

    //Test CustomerEvent
    describe("CustomerEvent: operator>>: should properly read the start time from the first line of input.txt");
    CustomerEvent e;
    in >> e;
    failCount += assertInt(1, e.getStart());
    describe("CustomerEvent: operator>>: should properly read the duration time from the first line of input.txt");
    failCount += assertInt(5, e.getDuration());
    describe("CustomerEvent: operator>>: should assume ARRIVAL type from the first line of input.txt");
    failCount += assertInt(CustomerEventType::ARRIVAL, e.getEventType());

    describe("CustomerEvent: operator>>: should properly read the start time from the second line of input.txt");
    CustomerEvent e2;
    in >> e2;
    failCount +=  assertInt(2, e2.getStart());
    describe("CustomerEvent: operator>>: should properly read the duration time from the second line of input.txt");
    failCount += assertInt(5, e2.getDuration());
    describe("CustomerEvent: operator>>: should assume ARRIVAL type from the second line of input.txt");
    failCount += assertInt(CustomerEventType::ARRIVAL, e2.getEventType());


    in.clear();
    in.seekg(0, in.beg);

    describe("CustomerEvent: operator>>: should read the proper number of lines from the file when reading until eof");
    unsigned int readCount = 0;
    CustomerEvent temp;
    while (in>>temp) {
        readCount++;
    }
    failCount += assertInt(10, readCount);

    describe("CustomerEvent: operator<: since e2 occurs later, it should have a lower priority than e");
    failCount +=  assertInt(0, e < e2);
    describe("CustomerEvent: operator<: since e occurs earlier, it should have a higher priority than e2");
    failCount +=  assertInt(1, e2 < e);

    //Test SimulationResult
    describe("SimulationResult: should properly store events processed");
    SimulationResult r(5, 6, "test");
    failCount += assertInt(5, r.getProcessedEventCount());
    describe("SimulationResult: should properly store average wait time");
    failCount += assertInt(6, r.getAverageWaitTime());
    describe("SimulationResult: should properly store output string");
    failCount += assertString("test", r.getOutput());

    //Test simulate()
    describe("simulate(): should return 0 events processed in a SimulationResult for an empty priority_queue");
    priority_queue<CustomerEvent> qe;
    SimulationResult resulte = simulate(qe);
    failCount += assertInt(0, resulte.getProcessedEventCount());
    describe("simulate(): should return 0 average wait time in a SimulationResult for an empty priority_queue");
    failCount += assertInt(0, resulte.getAverageWaitTime());
    describe("simulate(): should return only headers in output in a SimulationResult for an empty priority_queue");
    failCount += assertString("Simulation Begins\nSimulation Ends\n", resulte.getOutput());

    in.clear();
    in.seekg(0, in.beg);

    describe("priority_queue<CustomerEvent>: should have size() 10 after reading in from file");
    priority_queue<CustomerEvent> q;
    while (in>>temp) {
        q.push(temp);
    }
    failCount += assertInt(10, q.size());


    describe("simulate(): should return 10 events processed in a SimulationResult for a the priority_queue from input.txt");
    SimulationResult result = simulate(q);
    failCount += assertInt(10, result.getProcessedEventCount());
    describe("simulate(): should return 5.6 average wait time in a SimulationResult for a the priority_queue from input.txt");
    failCount += assertFloat(5.6, result.getAverageWaitTime());

    ifstream ifs ("simulation_output.txt");
    string s;
    getline (ifs, s, (char) ifs.eof());
    describe("simulate(): should return the same output as simulation_output.txt");
    failCount += assertString(s, result.getOutput());

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

    //Load the events for the queue from input.txt
    ifstream in;
    in.open("input.txt");
    CustomerEvent temp;
    priority_queue<CustomerEvent> q;
    while (in>>temp) {
        q.push(temp);
    }

    //Run the actual simulation
    SimulationResult result = simulate(q);

    //Log the ongoing output of the simulation
    cout << result.getOutput();

    //Print the final statistics of the simulation
    cout << endl;
    cout << "Final Statistics:" << endl;
    cout << "\t" << "Total number of people processed: " << result.getProcessedEventCount() << endl;
    cout << "\t" << "Average amount of time spent waiting: " << result.getAverageWaitTime() << endl;
    cout << endl;

    cout << "=========End Demo=========" << endl;

    //Exit with a 0 status code
    return 0;
}