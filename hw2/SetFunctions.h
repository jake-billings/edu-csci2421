/**
 * Name: Jake Billings
 * Date: 02/05/2018
 * Class: CSCI 2421
 * Description: Declaration file for the class Set, which extends ArrayBag with set features
 * Status: compiles and runs on csegrid
 */

#ifndef EDU_CSCI2421_SET_H
#define EDU_CSCI2421_SET_H

//Include iostream for << and >> implementations
#include <iostream>
//Include string for << and >> operations
#include <string>
//Include sstream for the >> operator to read one line at a time
#include <sstream>
//Include numeric limits for brute-force guessing in operation implementations
#include <limits>
//Incude std except because we need runtime_err
#include <stdexcept>
//Include ArrayBag vecuase we need to extend it
#include "ArrayBag.h"

//Use the standard namespace so we don't have to write std:: all the time
using namespace std;

/**
 * Set
 *
 * Class extends ArrayBag
 *
 * In this implementation, a set is an unordered group of unique integers.
 *  We override ArrayBag's add() to prevent the addition of multiple integers
 *  We also implement >>, <<, -, and - operators according to the homework problem
 */
class Set : public ArrayBag {
    friend class ArrayBag;

public:
    /**
     * add()
     *
     * overrides ArrayBag::add
     *
     * This implementation prevents the insertion of a value if it's already contained
     *  in the set.
     *
     * @param newEntry new entry to add to the set
     * @return true if the insert was sucessful; false if not
     */
    bool add(const int &a);

    /**
     * operator>>
     *
     * Reads a set from a stream
     *
     * Help used from https://stackoverflow.com/questions/42654293/how-to-read-integers-till-end-of-line
     *
     * @param in the input stream to read from (usually ifstream)
     * @param set the set address to insert data into
     * @return in
     */
    friend istream &operator>>(istream &in, Set &set);
    /**
     * operator<<
     *
     * outputs a set to an output stream as a tab-delimeted numbers
     *
     * ineffcient implementation: since we don't have access to the private underlying items array,
     *  we must make use of the available ArrayBag functions. This means we essentially have to guess
     *  what elements are in the set. This is inefficient if there are large numbers in the set.
     *  However, we assume all numbers are "close" to 0. Using this hueristic, we are able to process the example
     *  data set from the homework quickly.
     *
     * @param out the output stream (usually cout)
     * @param set the set to print
     * @return out
     */
    friend ostream &operator<<(ostream &out, Set &set);

    /**
     * operator+
     *
     * SET UNION OPERATOR
     *
     * returns the union of two set objects as a new set object
     *
     * ineffcient implementation: since we don't have access to the private underlying items array,
     *  we must make use of the available ArrayBag functions. This means we essentially have to guess
     *  what elements are in the set. This is inefficient if there are large numbers in the set.
     *  However, we assume all numbers are "close" to 0. Using this hueristic, we are able to process the example
     *  data set from the homework quickly.
     *
     * @param a The left side of the union operator
     * @param b The right side of the union operator
     * @return c The result of the union operator on a and b
     */
    friend Set operator+(Set &a, Set &b);

    /**
     * operator-
     *
     * SET INTERSECT OPERATOR
     *
     * returns the intersection of two set objects as a new set object
     *
     * ineffcient implementation: since we don't have access to the private underlying items array,
     *  we must make use of the available ArrayBag functions. This means we essentially have to guess
     *  what elements are in the set. This is inefficient if there are large numbers in the set.
     *  However, we assume all numbers are "close" to 0. Using this hueristic, we are able to process the example
     *  data set from the homework quickly.
     *
     * @param a The left side of the intersection operator
     * @param b The right side of the intersection operator
     * @return c The result of the intersection operator on a and b
     */
    friend Set operator-(Set &a, Set &b);
};


#endif //EDU_CSCI2421_SET_H
