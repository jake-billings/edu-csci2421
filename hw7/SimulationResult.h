/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Delaration file for SimulationResult class
 * Status: compiles and runs on csegrid
 */

//Include standard library dependancies
// we need string to store the simulation output
#include <string>

#ifndef EDU_CSCI2421_SIMULATIONRESULT_H
#define EDU_CSCI2421_SIMULATIONRESULT_H

//Use that standard namespace because this isn't production code, and it's more readable without "std::"
using namespace std;

/**
 * SimulationResult
 *
 * class
 *
 * immutable
 *
 * SimulationResult represents the resulting output and statistics of a bank teller simulation
 *  from this homework problem
 *
 * Required statistics:
 *  number of customers processed
 *  average time a customer waited
 *  exact string output
 */
class SimulationResult {
private:
    /**
     * processedEventCount
     *
     * unsigned int
     *
     * the number of CUSTOMERS/number of "ARRIVAL" events processed in the simulation
     *  this object represents
     *
     * Ex: 10
     */
    unsigned int processedEventCount;

    /**
     * averageWaitTime
     *
     * float
     *
     * the average amount of time a customer waited before being helped by the "teller"
     *  in the simulation
     *
     * Ex: 5.6
     */
    float averageWaitTime;

    /**
     * output
     *
     * string
     *
     * the simulation output as exemplified in the homework problem
     *
     * Ex: "...Processing an arrival event at time:	1..."
     */
    string output;
public:
    /**
     * SimulationResult()
     *
     * constructor: full
     *
     * creates a complete SimulationResult result object (assuming valid values for params)
     *
     * use this constructor since the object is intended to be immutable
     *
     * @param processedEventCount the number of events that were processed
     * @param averageWaitTime the average amount of time a customer waitied
     * @param output the string text output of the simulation
     */
    SimulationResult(unsigned int processedEventCount, float averageWaitTime, string output);

    //----Getters----
    // No setters are included because this object is intended to be, for the most part, immutable
    unsigned int getProcessedEventCount() const;
    float getAverageWaitTime() const;
    const string getOutput() const;
};


#endif //EDU_CSCI2421_SIMULATIONRESULT_H
