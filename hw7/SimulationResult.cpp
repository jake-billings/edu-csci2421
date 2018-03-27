/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Implementation file for SimulationResult class
 * Status: compiles and runs on csegrid
 */

#include "SimulationResult.h"

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
SimulationResult::SimulationResult(unsigned int processedEventCount, float averageWaitTime, string output) : processedEventCount(
        processedEventCount), averageWaitTime(averageWaitTime), output(output) {}

//----Getters----
// No setters are included because this object is intended to be, for the most part, immutable

unsigned int SimulationResult::getProcessedEventCount() const {
    return processedEventCount;
}

float SimulationResult::getAverageWaitTime() const {
    return averageWaitTime;
}

const string SimulationResult::getOutput() const {
    return output;
}
