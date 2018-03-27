/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Implementation file for Simulation function
 * Status: compiles and runs on csegrid
 */


//Include std libraries
// sstream is needed to collect the output as a string so that we can unit test it
#include <sstream>
// stdexcept is needed to throw an error if the switch finds an event type it doesn't know about (this currently can't happen)
#include <stdexcept>
// queue is need for the priority queue for event processing
#include <queue>

//Inclue project-specific dependencies
#include "SimulationResult.h"
#include "CustomerEvent.h"

//Use that standard namespace because this isn't production code, and it's more readable without "std::"
using namespace std;

#ifndef EDU_CSCI2421_SIMULATION_H
#define EDU_CSCI2421_SIMULATION_H

/**
 * simulate()
 *
 * run the actual bank simulation from the homework problem
 *  customer arrivals are represented by CustomerEvent where the type is "ARRIVAL"
 *  these arrivals imply departures
 *  departures can only occur after a customer has waited in line then processed a transaction
 *   at the head of the line
 *
 * the actual messy part
 *
 * @param q a priority_queue containing all "ARRIVAL" events for simulation
 * @return a SimulationResult object containing output and statistics from the simulation
 */
SimulationResult simulate(priority_queue<CustomerEvent> q);

#endif //EDU_CSCI2421_SIMULATION_H
