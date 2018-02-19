/**
 * Name: Jake Billings
 * Date: 03/08/2018
 * Class: CSCI 2421
 * Description: declaration file for SearchResult class
 */

#ifndef EDU_CSCI2421_SEARCHRESULT_H
#define EDU_CSCI2421_SEARCHRESULT_H

/**
 * SearchResult
 *
 * class
 *
 * SearchResult represents the combined information we attempt to collect
 *  from each call to searchByWord() function
 *
 * Each call should return the index at which an element was found and the
 *  number of iterations it took to get there. This class stores that.
 */
class SearchResult {
public:
    /**
     * SearchResult
     *
     * constructor
     *
     * @param index the index at which the element that was searched for was found
     * @param iterations the number of iterations it took to determine index for the element that was searched for
     */
    SearchResult(int index, unsigned int iterations);

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
    int getIndex() const;

    /**
     * getIterations()
     *
     * returns iterations
     *
     * the number of iterations it took to determine index for the element that was searched for
     *
     * @return iterations
     */
    unsigned int getIterations() const;

private:
    /**
     * index
     *
     * int
     *
     * the index at which the element that was searched for was found
     *
     * index is -1 if the element was not found; otherwise, index is >=0.
     */
    int index;

    /**
     * iterations
     *
     * unsigned int
     *
     * the number of iterations it took to determine index for the element that was searched for
     */
    unsigned int iterations;
};

#endif //EDU_CSCI2421_SEARCHRESULT_H
