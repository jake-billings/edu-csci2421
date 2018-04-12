/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2421
 * Description: implementation file for string utility functions
 */

//Include the header file so we can implement it
#include "StrUtil.h"

/**
 * toLower()
 *
 * utility function to lowercase all letters of a string
 *
 * @param old the old string
 * @return the lowercased string
 */
string toLower(string old) {
    string newStr;
    ostringstream os(newStr);
    for (unsigned int i = 0; i < old.size(); i++) {
        os << (char) tolower(old[i]);
    }
    return os.str();
}

/**
 * scrub()
 *
 * utility function to lowercase all letters of a string AND
 *  remove punctuation characters
 *
 * @param old the old string
 * @return the scrubbed string
 */
string scrub(string old) {
    string newStr;
    ostringstream os(newStr);
    for (unsigned int i = 0; i < old.size(); i++) {
        char character = tolower(old[i]);
        if (character!='.') {
            os << character;
        }
    }
    return os.str();
}