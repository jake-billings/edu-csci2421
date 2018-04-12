/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2421
 * Description: declaration file for Dictionary class
 */

//Include string since we use strings
#include <string>
//Includ LinkedList since we use LnkedLists
#include "LinkedList.hpp"

//use the standard namespace so I don't have to type "std::"
// all the time
using namespace std;

#ifndef EDU_CSCI2421_DICTIONARY_H
#define EDU_CSCI2421_DICTIONARY_H

#define DEFAULT_HASH_MOD 1373

/**
 * Dictionary
 *
 * class
 *
 * This dictionary knows if a word has been stored in it or not.
 *
 * This class is the start of a "standard" dictionary object (like JS and Python)
 *  However, this class does not implement the storage of items with Key, Value.
 *  This class only implements the ability to check if a string has been added or
 *  not.
 *
 * The implementation uses the "hash" library function and "hashMod" buckets.
 *  The default constructor instatiates the Dictionary with 1373 buckets.
 *
 * Hash collisions are handled using LinkedLists
 */
class Dictionary {
private:
    /**
     * hashMod
     *
     * unsigned int
     *
     * the number of buckets
     *  this is called hashMod because "size" should refer to the number of words in the dictionary
     *  a modulus of this amount is performed on the hash
     */
    unsigned int hashMod;

    /**
     * buckets
     *
     * LinkedList<string> array
     *
     * ponter to the first "bucket" in an array
     *  that is hashMod buckets long
     */
    LinkedList<string> *buckets;

    /**
     * _hash
     *
     * private method
     *
     * calculates the hash of the string and performs the modulus by bucket number
     *
     * @param s string to hash
     * @return hash(s) % hashMod
     */
    unsigned long _hash(const string &s);
public:
    /**
     * Dictionary
     *
     * constructor
     *
     * instatiate a Dictionary with 1373 buckets
     */
    Dictionary();

    /**
     * Dictionary
     *
     * constructor
     *
     * instantiate a Dictionary with a custom number of buckets
     *
     * @param hashMod the number of buckets to start with
     */
    Dictionary(unsigned int hashMod);

    /**
     * ~Dictionary()
     *
     * destructor
     *
     * deallocates the array of linkedlists
     */
    ~Dictionary();

    /**
     * Dictionary
     *
     * copy constructor
     *
     * throws an error because writing a copy constructor is not part of this assignment
     *
     * @param original the dictionary to copy
     */
    Dictionary(const Dictionary &original);

    /**
     * Dictionary
     *
     * assignment operator
     *
     * throws an error because writingassignment operator is not part of this assignment
     *
     * @param original the other dictionary
     */
    Dictionary operator=(const Dictionary &other);

    /**
     * insert()
     *
     * inserts a word into the dictionary
     *  the word is hashed
     *  the hash is moded by the number of buckets
     *  the hash is inserted into the LinkedList at that index
     *
     * @param word word to insert
     */
    void insert(string word);

    /**
     * contains()
     *
     * returns true if this dictionary contains the word
     *  the word is hashed
     *  the hash is moded by the number of buckets
     *  we call contains() on the LinkedList at that index
     *
     * @param word the word to check
     * @return true if this dictionary contains the word
     */
    bool contains(string word);

};


#endif //EDU_CSCI2421_DICTIONARY_H
