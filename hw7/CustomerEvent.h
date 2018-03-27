/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Declaration file for CustomerEvent class
 * Status: compiles and runs on csegrid
 */


#ifndef EDU_CSCI2421_CUSTOMEREVENT_H
#define EDU_CSCI2421_CUSTOMEREVENT_H

//Include standard libraries
//istream is required to define the >> opeartor
#include <istream>

//Include custom dependencies
//Include CustomerEventType.h so that we can reference the CustomerEventType enum
#include "CustomerEventType.h"

//Use that standard namespace because this isn't production code, and it's more readable without "std::"
using namespace std;

/**
 * CustomerEvent
 *
 * class
 *
 * The CustomerEvent class represents either the arrival or departure of a customer from
 *  simulated bank line. The simulated bank line is a priority_queue.
 *
 * The class stores the start time of an event and its duration. It takes "0 time" to depart, and it takes
 *  some number of minutes to complete a transaction once at the head of the line.
 *
 * An enum is used to represent arrival vs. departure in the data structure.
 *
 * In the simulation, arrival events create departure events in the queue.
 *
 * Time between arrival and departure is the time a customer spends in the store. Subtracting the duration of the
 * "ARRIVAL" event yields wait time.
 *
 * all DEPARTURE events can be properly inferred from ARRIVAL events
 *
 * See operator<: an event that occurs "earlier in time" is a "higher priority" and occurs earlier
 */
class CustomerEvent {
public:
    /**
     * start
     *
     * unsigned int
     *
     * the time index in minutes from the start of the simulation at which this event begins
     *
     * Ex: 1
     */
    unsigned int start;

    /**
     * duration
     *
     * unsigned int
     *
     * the number of minutes starting from time index "start" that it takes for this event to complete.
     *
     * Ex: it takes "0 time" to actually depart.
     * Ex: it could take "5 minutes" to complete a transaction then complete a depart event.
     */
    unsigned int duration;

    /**
     * eventType
     *
     * CustomerEventType
     *
     * The type of event that occurs as represented by the CustomerEventType enum. It
     *  could be an "ARRIVAL" or "DEPARTURE" event.
     */
    CustomerEventType eventType;

    /**
     * CustomerEvent()
     *
     * constructor: empty
     *
     * instatiaties a completely empty customer event object
     *  used just before reading an object from a file using the >> operator
     */
    CustomerEvent();

    /**
     * CustomerEvent()
     *
     * constructor: full
     *
     * creates a complete; properly formatted CustomerEvent object (assuming non-null values for params)
     *
     * @param start when this event starts
     * @param duration how long this event takes
     * @param eventType the type of even (ARRIVAL or DEPARTURE) (see CustomerEventType.h)
     */
    CustomerEvent(unsigned int start, unsigned int duration, CustomerEventType eventType);


    /**
     * &operator>>
     *
     * reads a CustomerEvent from a line on an input stream using >> operators
     *  assumes the event is an arrival event
     *  uses the format from the homework problem
     *  E.g. "88  3" for an event that starts at minute 88 and takes three minutes
     *
     * See input.txt
     *
     * @param in the input stream from which to read this CustomerEvent object (e.g. ifstream)
     * @param event an empty CustomerEvent object from the empty constructor
     * @return the parameter in
     */
    friend istream &operator>>(istream &in, CustomerEvent &event);

    /**
     * operator<
     *
     * "less than" operator for CustomerEvent objects
     *   used by the priority_queue to order events in time as they are inserted into the queue
     *   since, the object with the "highest" priority is first, and low time values occur earlier in time, and
     *   we expect for events that occur earlier in time to be at the top of the queue, this operator is "inverted"
     *
     *   we use the ">" operator on the "start" property of the a and b CustomerEvent objects.
     *
     *   in other words, an event that occurs "earlier in time" is a "higher priority" and occurs earlier
     *
     * @param a the lefthand operand
     * @param b the righthand operand
     * @return true if a < b (see above)
     */
    friend bool operator<(CustomerEvent a, CustomerEvent b);

    //----Getters----
    // No setters are included because this object is intended to be, for the most part, immutable
    // the >> operator is officially allowed to populate this object
    CustomerEventType getEventType() const;

    unsigned int getStart() const;

    unsigned int getDuration() const;
};


#endif //EDU_CSCI2421_CUSTOMEREVENT_H
