/**
 * Name: Jake Billings
 * Date: 02/05/2018
 * Class: CSCI 2421
 * Description: Implementation file for the class Set, which extends ArrayBag with set features (see Set class docs)
 * Status: compiles and runs on csegrid
 */
#include "SetFunctions.h"

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
bool Set::add(const int &newEntry) {
    //Return false without inserting element if the element is already in the parent's array bag
    if (this->getFrequencyOf(newEntry) > 0) return false;

    //Call the superclass to perform the insert
    return ArrayBag::add(newEntry);
}

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
istream& operator>>(istream &in, Set &set) {
    //Read one line from the input stream and create an istringstream for it
    string line;
    getline(in, line);
    istringstream is(line);

    //Read all whitespace-delimited "word" from the line we read
    // try to parse it to an int; if there's an error doing that,
    // throw our own error to meet the validation requirement for
    // the extra credit on this assignment
    string word;
    while (is >> word) {
        try {
            //try to parse the string
            // if it fails, the string isn't a valid
            // integer, and we need to throw our own error
            int i = stoi(word);

            set.add(i);
        } catch (const invalid_argument& e) {
            // fullfill validation requirement by catching the invalid_argument error
            // and throwing our own error
            throw runtime_error("error parsing set from input stream; malformed/non-int word found in input stream");
        }
    }

    //Return the input stream
    return in;
}

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
ostream& operator<<(ostream &out, Set &set) {
    //Keep track of how many elements we printed
    unsigned int outputCount = 0;

    //Check all positive and nexative numbers from [0-max int]
    // If a number is in the set, print it and increment outputCount
    // If we manage to guess all the numbers in the set, break the loop so we
    // don't have to check the rest of the possible integers.
    for (int i = 0; (i < numeric_limits<int>::max() && outputCount < set.getCurrentSize()); i++) {
        if (set.contains(i)) {
            const unsigned int count = set.getFrequencyOf(i);
            for (unsigned int j = 0; j<count; j++) {
                out << i << '\t';
                outputCount++;
            }
        }
        if (set.contains(-i)) {
            const unsigned int count = set.getFrequencyOf(-i);
            for (unsigned int j = 0; j<count; j++) {
                out << -i << '\t';
                outputCount++;
            }
        }
    }

    return out;
}

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
Set operator+(Set &a, Set &b) {
    //Instatiate a new set c
    Set c;

    //Keep track of the total number of elements and the number of elements we have checked
    const unsigned int totalElementCount = a.getCurrentSize() + b.getCurrentSize();
    unsigned int comparedElementCount = 0;

    //Check all positive and negative integers to see if they're in the set
    // if we manage to check all of the integers in the set, break the loop
    // so that we don't bother with many integers that aren't
    // Add any int that is in either a and b to set c
    for (int i = 0; (i < numeric_limits<int>::max())&&(comparedElementCount<totalElementCount); i++) {
        unsigned int freq = a.getFrequencyOf(i) + b.getFrequencyOf(i);
        comparedElementCount += freq;
        if (freq>0) c.add(i);
        unsigned int freqNeg = a.getFrequencyOf(-i) + b.getFrequencyOf(-i);
        comparedElementCount += freqNeg;
        if (freqNeg>0) c.add(-i);
    }

    //Return set c by value
    return c;
}

/**
 * operator-
 *
 * SET DIFFERENCE OPERATOR
 *
 * removes all elements that are in b from a
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
Set operator-(Set &a, Set &b) {
    //Instantiate set c to track the result
    Set c;

    //Keep track of the total number of elements and the number of elements we have checked
    const unsigned int totalElementCount = a.getCurrentSize() + b.getCurrentSize();
    unsigned int comparedElementCount = 0;


    //Check all positive and negative integers to see if they're in the set
    // if we manage to check all of the integers in the set, break the loop
    // so that we don't bother with many integers that aren't
    // Add any int that is in both a and b to set c
    for (int i = 0; (i < numeric_limits<int>::max())&&(comparedElementCount<totalElementCount); i++) {
        unsigned int freqA = a.getFrequencyOf(i);
        unsigned int freqB = b.getFrequencyOf(i);
        comparedElementCount += freqA;
        comparedElementCount += freqB;
        if (freqA>freqB) c.add(i);

        unsigned int freqANeg = a.getFrequencyOf(-i);
        unsigned int freqBNeg = b.getFrequencyOf(-i);
        comparedElementCount += freqANeg;
        comparedElementCount += freqBNeg;
        if (freqANeg>freqBNeg) c.add(-i);
    }

    //Return set c by value
    return c;
}