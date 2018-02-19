/**
 * Name: Jake Billings
 * Date: 03/08/2018
 * Class: CSCI 2421
 * Description: declaration file for Dictionary class
 */

#ifndef EDU_CSCI2421_DICTIONARY_H
#define EDU_CSCI2421_DICTIONARY_H

//include std library doubly linked list
#include <list>
//Include runtime_error
#include <stdexcept>
//Include iostream for "endl" and getline in << and >>
#include <iostream>

//Include classes from this HW that we need
#include "SearchResult.h"
#include "DictEntry.h"

//use std, so we don't have to type "std::" all the time
using namespace std;

/**
 * Dictionary
 *
 * wrapper class
 *
 * contains a doubly linked list of DictEntry objects and exposes
 *  select functions for searching and sorting
 *
 * designed based on constraints of the homework assignment
 */
class Dictionary {
private:
    /**
     * entries
     *
     * private list<DictEntry>
     *
     * internal doubly linked list containing DictEntries
     */
    list<DictEntry> entries;
public:
    /**
     * getSize()
     *
     * return the number of words in this dictionary
     *
     * @return the number of words in the entries array of this dictionary
     */
    unsigned int getSize();

    /**
     * push_back()
     *
     * append an entry to the end of the dictionary
     *
     * @param entry the entry to append
     */
    void push_back(DictEntry entry);

    /**
     * sort()
     *
     * sort the dictionary in alphabetical order
     */
    void sort();

    /**
     * isSorted()
     *
     * returns true if the entire dictionary is sorted alphabetically
     *
     * @return true if the entire dictionary is sorted alphabetically
     */
    bool isSorted();

    /**
     * searchByWord()
     *
     * searches this dictionary from front to back in search of a DictEntry object for which
     *  the word matches word
     *
     * @param word the string word to search for
     * @return a SearchResult object that contains the index at which the DictEntry was found and how many iterations it took
     */
    SearchResult searchByWord(string word);

    /**
     * searchByWordReverse()
     *
     * searches this dictionary from back to front in search of a DictEntry object for which
     *  the word matches word
     *
     * @param word the string word to search for
     * @return a SearchResult object that contains the index at which the DictEntry was found and how many iterations it took
     */
    SearchResult searchByWordReverse(string word);

    /**
     * &operator>>
     *
     * reads a dictionary from an input stream (which is usally dictionary.txt)
     *
     * @param in input stream to read from (usually ifstream)
     * @param dict the dictionary object to read into
     * @return the input stream in
     */
    friend istream &operator>>(istream &in, Dictionary &dict);

    /**
     * &operator<<
     *
     * prints the dictionary to an output stream from back to front
     *
     * @param out the output stream to which this dictionary will be printed (ex: ofstream to "revsorted.txt")
     * @param dict the dictionary object to print to the output stream
     * @return the output stream out
     */
    friend ostream &operator<<(ostream &out, Dictionary &dict);
};


#endif //EDU_CSCI2421_DICTIONARY_H
