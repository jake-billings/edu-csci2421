/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2421
 * Description: declaration file for string utility functions
 */
#include<string>
#include<sstream>

//use the standard namespace so I don't have to type "std::"
// all the time
using namespace std;

#ifndef EDU_CSCI2421_STRUTIL_H
#define EDU_CSCI2421_STRUTIL_H

/**
 * toLower()
 *
 * utility function to lowercase all letters of a string
 *
 * @param old the old string
 * @return the lowercased string
 */
string toLower(string old);

/**
 * scrub()
 *
 * utility function to lowercase all letters of a string AND
 *  remove punctuation characters
 *
 * @param old the old string
 * @return the scrubbed string
 */
string scrub(string old);

#endif //EDU_CSCI2421_STRUTIL_H
