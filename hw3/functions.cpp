/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description: function implementations for sorting and searching vectors of Vehicle classes
 * Status: compiles and runs on csegrid
 */

//Include the header file
#include "functions.h"

/**
 * sortByMake()
 *
 * MUTATES the vector referenced by inventoryPtr
 *
 * performs an in-place bubble sort on the vector referenced by inventoryPtr in ASCENDING order
 *  with respect to make
 *
 * the c++ implementation of string ordering is alphabetization, so this function alphabetizes by
 *  make
 *
 * @param inventoryPtr a pointer to the vehicle array that we are trying to sort
 */
void sortByMake(vector<Vehicle> *inventoryPtr) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        for (unsigned long j = 0; j < inventoryPtr->size() - 1; j++) {
            Vehicle v = (*inventoryPtr)[j];
            if (v.getMake() > (*inventoryPtr)[j + 1].getMake()) {
                (*inventoryPtr)[j] = (*inventoryPtr)[j + 1];
                (*inventoryPtr)[j + 1] = v;
            }
        }
    }
}

/**
 * sortByModel()
 *
 * MUTATES the vector referenced by inventoryPtr
 *
 * performs an in-place bubble sort on the vector referenced by inventoryPtr in ASCENDING order
 *  with respect to model
 *
 * the c++ implementation of string ordering is alphabetization, so this function alphabetizes by
 *  model
 *
 * @param inventoryPtr a pointer to the vehicle array that we are trying to sort
 */
void sortByModel(vector<Vehicle> *inventoryPtr) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        for (unsigned long j = 0; j < inventoryPtr->size() - 1; j++) {
            Vehicle v = (*inventoryPtr)[j];
            if (v.getModel() > (*inventoryPtr)[j + 1].getModel()) {
                (*inventoryPtr)[j] = (*inventoryPtr)[j + 1];
                (*inventoryPtr)[j + 1] = v;
            }
        }
    }
}

/**
 * sortByYear()
 *
 * MUTATES the vector referenced by inventoryPtr
 *
 * performs an in-place bubble sort on the vector referenced by inventoryPtr in ASCENDING order
 *  with respect to year
 *
 * @param inventoryPtr a pointer to the vehicle array that we are trying to sort
 */
void sortByYear(vector<Vehicle> *inventoryPtr) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        for (unsigned long j = 0; j < inventoryPtr->size() - 1; j++) {
            Vehicle v = (*inventoryPtr)[j];
            if (v.getYear() > (*inventoryPtr)[j + 1].getYear()) {
                (*inventoryPtr)[j] = (*inventoryPtr)[j + 1];
                (*inventoryPtr)[j + 1] = v;
            }
        }
    }
}

/**
 * _binSearchRecYear()
 *
 * Performs the recursion in a recursive binary search
 *
 * PRIVATE: this is not the exposed implementation of binary search. This is the recursive portion of binary search
 *  only. It is called by the public exposed binSearchRecYear()
 *
 * With the proper init paramters, this function will perform a binary search. See binSearchRecYear() for those
 *  starting parameters.
 *
 * This function assumes the inventor vector is sorted.
 *
 * @private
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @param left the left side of the search region for this iteration
 * @param right the right side of the search region for this iteration
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *_binSearchRecYear(vector<Vehicle> *inventoryPtr, unsigned int year, unsigned long left, unsigned long right) {
    //Calculate the middle index in the given search region for this iteration
    const unsigned long midpoint = (right - left) / 2 + left;

    //If the midpoint is the target, terminate
    if ((*inventoryPtr)[midpoint].getYear() == year) return &(*inventoryPtr)[midpoint];

    //If the region still contains elements, select a smaller region and continue searching
    if (left < right) {
        //If the target is to the left, select the right to the righ
        if ((*inventoryPtr)[midpoint].getYear() < year) {
            return _binSearchRecYear(inventoryPtr, year, midpoint + 1, right);
        }

        //If the target is to the right, select the left to the left
        return _binSearchRecYear(inventoryPtr, year, left, midpoint - 1);
    }

    //There's nothing left in the range, so we didn't find the element because it's not
    // in the list.
    // Return null
    return nullptr;
}

/**
 * binSearchRecYear()
 *
 * Performs a recursive binary search for a vehicle with a given year in a SORTED vector of vehicles
 *
 * This function checks that the inventor vector is sorted in ASCENDING order. If it isn't, we throw a runtime_error.
 *
 * validates and sets init params then calls _binSearchRecYear()
 *
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *binSearchRecYear(vector<Vehicle> *inventoryPtr, unsigned int year) {
    //Validate that the items in the incoming vector are already sorted
    // throw a runtime exception if they aren't
    bool invalidOrderingExists = false;
    for (unsigned int i = 1; i < inventoryPtr->size(); i++) {
        if ((*inventoryPtr)[i - 1].getYear() > (*inventoryPtr)[i].getYear()) invalidOrderingExists = true;
    }
    if (invalidOrderingExists) {
        throw runtime_error(
                "error starting recursive binary search; incoming vector MUST be sorted in ascending order before calling search function");
    }

    //Call the actual recursive function with initial params
    return _binSearchRecYear(inventoryPtr, year, 0, inventoryPtr->size() - 1);
}

/**
 * binSearchIterYear()
 *
 * Performs an iterative binary search for a vehicle with a given year in a SORTED vector of vehicles
 *
 * This function checks that the inventor vector is sorted in ASCENDING order. If it isn't, we throw a runtime_error.
 *
 * validates and sets init params then iterates
 *
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *binSearchIterYear(vector<Vehicle> *inventoryPtr, unsigned int year) {
    //Validate that the items in the incoming vector are already sorted
    // throw a runtime exception if they aren't
    bool invalidOrderingExists = false;
    for (unsigned int i = 1; i < inventoryPtr->size(); i++) {
        if ((*inventoryPtr)[i - 1].getYear() > (*inventoryPtr)[i].getYear()) invalidOrderingExists = true;
    }
    if (invalidOrderingExists) {
        throw runtime_error(
                "error starting iterative binary search; incoming vector MUST be sorted in ascending order before calling search function");
    }

    //Set initial variable values
    unsigned long left = 0;
    unsigned long right = inventoryPtr->size() - 1;
    Vehicle *resultPtr = nullptr;

    //Iterate while there are items in the range
    while (left <= right) {
        //Calculate the middle index in the given search region for this iteration
        const unsigned long midpoint = (right - left) / 2 + left;

        //If the element at the midpoint matches the search target, we're done.
        // break and return
        if ((*inventoryPtr)[midpoint].getYear() == year) {
            resultPtr = &(*inventoryPtr)[midpoint];
            break;
        }

        //If left == right, we ran out of space;
        // increment left to terminate the actual loop
        //Otherwise, select the subrange based on which
        // side is more likely to contain our target search result
        if (left == right) {
            left++;
        } else if ((*inventoryPtr)[midpoint].getYear() < year) {
            left = midpoint + 1;
        } else {
            right = midpoint - 1;
        }
    }

    return resultPtr;
}

/**
 * slowSearchYear()
 *
 * performs a direct iterative search over a vector of vehicles by year
 *
 * nothing is required about the array (it doesn't need to be sorted)
 *
 * this algorithm is used in unit tests for binary search algorithms
 *
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *slowSearchYear(vector<Vehicle> *inventoryPtr, unsigned int year) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        if ((*inventoryPtr)[i].getYear() == year) return &(*inventoryPtr)[i];
    }

    return nullptr;
}

