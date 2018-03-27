/**
 * Name: Jake Billings
 * Date: 03/26/2018
 * Class: CSCI 2421
 * Description: Implementation file for CustomerEvent class
 * Status: compiles and runs on csegrid
 */

//Include the class file
#include "CustomerEvent.h"

/**
 * CustomerEvent()
 *
 * constructor: empty
 *
 * instatiaties a completely empty customer event object
 *  used just before reading an object from a file using the >> operator
 */
CustomerEvent::CustomerEvent() {}

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
CustomerEvent::CustomerEvent(unsigned int start, unsigned int duration, CustomerEventType eventType) : start(start), duration(duration), eventType(eventType) {}


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
istream &operator>>(istream &in, CustomerEvent &event) {
    in >> event.start;
    in >> event.duration;
    event.eventType = CustomerEventType::ARRIVAL;

    return in;
}

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
bool operator<(CustomerEvent a, CustomerEvent b) {
    return a.getStart() > b.getStart();
}

//----Getters----
// No setters are included because this object is intended to be, for the most part, immutable
// the >> operator is officially allowed to populate this object

unsigned int CustomerEvent::getStart() const {
    return start;
}

unsigned int CustomerEvent::getDuration() const {
    return duration;
}

CustomerEventType CustomerEvent::getEventType() const {
    return eventType;
}
