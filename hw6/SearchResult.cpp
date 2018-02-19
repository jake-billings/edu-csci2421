/**
 * Name: Jake Billings
 * Date: 03/08/2018
 * Class: CSCI 2421
 * Description: implementation file for SearchResult class
 */

#include "SearchResult.h"

/**
 * SearchResult
 *
 * constructor
 *
 * @param index the index at which the element that was searched for was found
 * @param iterations the number of iterations it took to determine index for the element that was searched for
 */
SearchResult::SearchResult(int index, unsigned int iterations) : index(index), iterations(iterations) {}

/**
 * getIndex()
 *
 * returns index
 *
 * the index at which the element that was searched for was found
 *
 * index is -1 if the element was not found; otherwise, index is >=0.
 *
 * @return index
 */
int SearchResult::getIndex() const {
    return index;
}

/**
 * getIterations()
 *
 * returns iterations
 *
 * the number of iterations it took to determine index for the element that was searched for
 *
 * @return iterations
 */
unsigned int SearchResult::getIterations() const {
    return iterations;
}