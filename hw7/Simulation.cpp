/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Implementation file for Simulation function
 * Status: compiles and runs on csegrid
 */

//Include the function header
#include "Simulation.h"

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
SimulationResult simulate(priority_queue<CustomerEvent> q) {
    //in order to create and unit test the exact desired output
    // of the homework problem, we store simulation output in a string
    // on the SimulationResult object
    string line;
    ostringstream os(line);

    //Log the start of the simulation
    os << "Simulation Begins" << endl;

    //Incrementing counter for the current time
    // doesn't increment by 1's
    // increments with start times in the priority queue
    unsigned int time = 0;

    //The amount of remaining time for which the "teller"
    // at the front of the line will be "blocked" from
    // processing further events at time index "time"
    unsigned int blockedTime = 0;

    //A running total of the amount of time for which
    // customers were blocked frokm processing their
    // transactions
    unsigned int waitTimeTotal = 0;

    //Store the original size of the queue in order to
    // have a customer count for calculating average
    // wait time
    unsigned int size = q.size();

    //Loop until the queue is empty
    while (q.size() > 0) {
        //grab the top element from the queue
        // by the < operator in CustomerEvent, this will
        // be the earliest event in the queue that has
        // not be processed
        CustomerEvent e = q.top();
        q.pop();

        //Update time and keep track of how much passed
        unsigned int oldTime = time;
        if (e.getStart() > time) time = e.getStart();
        unsigned int timePassed = time - oldTime;

        //Update "blockedTime" so we know how much longer
        // the next "arrival" will have to wait
        if (timePassed > blockedTime) {
            blockedTime = 0;
        } else {
            blockedTime -= timePassed;
        }

        //Handle CustomerEvents based on their CustomerEventType
        switch (e.getEventType()) {
            case (CustomerEventType::ARRIVAL):
                //"Arrivals" create departure events
                os << "Processing an arrival event at time:\t" << e.getStart() << endl;

                //Departure events occur in the future after the customers ahead of us
                // in line have finished, and we have also finished
                q.push(CustomerEvent(time + blockedTime + e.getDuration(), 0, DEPARTURE));

                //Keep track of the time we had to wait in order to calculate the average later
                waitTimeTotal += blockedTime;

                //Block future customers while we perform our transaction
                blockedTime += e.getDuration();
                break;
            case (CustomerEventType::DEPARTURE):
                os << "Processing a departure event at time:\t" << e.getStart() << endl;
                break;
            default:
                throw new runtime_error("error: simulate(): unknown event type in priority_queue");
        }

    }

    //Calculate averageWaitTime
    // Special case: size=0 -> averageWaitTime=0
    float averageWaitTime;
    if (size != 0) {
        averageWaitTime = ((float) waitTimeTotal) / size;
    } else {
        averageWaitTime = 0;
    }

    //Log final message
    os << "Simulation Ends" << endl;

    //Wrap our data in a SimulationResult object
    return SimulationResult(size, averageWaitTime, os.str());
}