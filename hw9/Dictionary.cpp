/**
 * Name: Jake Billings
 * Date: 04/11/2018
 * Class: CSCI 2421
 * Description: implementation file for Dictionary class
 */

//Include Dictionary.h so we can implement it
#include "Dictionary.h"

/**
 * Dictionary
 *
 * constructor
 *
 * instantiate a Dictionary with a custom number of buckets
 *
 * @param hashMod the number of buckets to start with
 */
Dictionary::Dictionary(unsigned int hashMod) {
    this->hashMod = hashMod;
    this->buckets = new LinkedList<string>[hashMod];
}

/**
 * Dictionary
 *
 * constructor
 *
 * instatiate a Dictionary with 1373 buckets
 */
Dictionary::Dictionary() : Dictionary(DEFAULT_HASH_MOD) {};

/**
 * ~Dictionary()
 *
 * destructor
 *
 * deallocates the array of linkedlists
 */
Dictionary::~Dictionary() {}

/**
 * Dictionary
 *
 * copy constructor
 *
 * throws an error because writing a copy constructor is not part of this assignment
 *
 * @param original the dictionary to copy
 */
Dictionary::Dictionary(const Dictionary &original) {
    throw runtime_error("dictionary copy constructor is not implemented");
}

/**
 * Dictionary
 *
 * assignment operator
 *
 * throws an error because writingassignment operator is not part of this assignment
 *
 * @param original the other dictionary
 */
Dictionary Dictionary::operator=(const Dictionary &other) {
    throw runtime_error("dictionary assignment operator is not implemented");
}

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
unsigned long Dictionary::_hash(const string &s) {
    hash<string> hashStr;
    unsigned long hash = hashStr(s);
    unsigned long rHash = hash % this->hashMod;
    return rHash;
}

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
void Dictionary::insert(string word) {
    LinkedList<string> *list = &this->buckets[this->_hash(word)];
    list->push_front(word);
}

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
bool Dictionary::contains(string word) {
    LinkedList<string> *list = &this->buckets[this->_hash(word)];
    return list->contains(word);
}