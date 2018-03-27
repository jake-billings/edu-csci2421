/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Declaration file for CustomerEventType enum
 * Status: compiles and runs on csegrid
 */

#ifndef EDU_CSCI2421_CUSTOMEREVENTTYPE_H
#define EDU_CSCI2421_CUSTOMEREVENTTYPE_H

/**
 * CustomerEventType
 *
 * enum
 *
 * represents the types of CustomerEvent that could occur during simulation
 *  a processable event is either "ARRIVAL" or "DEPARTURE"
 *  in simulate() in Simulation.cpp, a switch statement uses this to process each
 *   event appropriately
 * all DEPARTURE events can be properly inferred from ARRIVAL events
 */
enum CustomerEventType {
    /**
     * ARRIVAL
     *
     * enum value
     *
     * a customer has arrived - add the appropriate amount of "blocked time"/"wait time"
     *  then create a corresponding "DEPARTURE" event
     *
     * this is the default event type in the >> operator since the input file contains only arrival events
     *
     * all DEPARTURE events can be properly inferred from ARRIVAL events
     */
    ARRIVAL,

    /**
     * DEPARTURE
     *
     * enum value
     *
     * a customer has departed - remove the appropriate amount of "blocked time"
     * all DEPARTURE events can be properly inferred from ARRIVAL events
     */
    DEPARTURE
};

#endif //EDU_CSCI2421_CUSTOMEREVENTTYPE_H
