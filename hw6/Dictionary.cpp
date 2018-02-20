/**
 * Name: Jake Billings
 * Date: 03/08/2018
 * Class: CSCI 2421
 * Description: implementation file for Dictionary class
 */

#include "Dictionary.h"

/**
 * getSize()
 *
 * return the number of words in this dictionary
 *
 * @return the number of words in the entries array of this dictionary
 */
unsigned int Dictionary::getSize() {
    return this->entries.size();
}

/**
 * push_back()
 *
 * append an entry to the end of the dictionary
 *
 * @param entry the entry to append
 */
void Dictionary::push_back(DictEntry entry) {
    this->entries.push_back(entry);
}

/**
 * sort()
 *
 * sort the dictionary in alphabetical order
 */
void Dictionary::sort() {
    this->entries.sort();
}

/**
 * isSorted()
 *
 * returns true if the entire dictionary is sorted alphabetically
 *
 * @return true if the entire dictionary is sorted alphabetically
 */
bool Dictionary::isSorted() {
    //Spawn an iterator to use
    list<DictEntry>::iterator it = this->entries.begin()++;
    list<DictEntry>::iterator last = this->entries.begin();

    //For each element that isn't the last or second to last element,
    while (it != this->entries.end()) {
        //Return false if out of order
        if (*it < *last) return false;

        //Advance the iteration
        last = it;
        it++;
    }

    //If we haven't returned false yet, return true because no
    // element was out of order
    return true;
}

/**
 * searchByWord()
 *
 * searches this dictionary from front to back in search of a DictEntry object for which
 *  the word matches word
 *
 * @param word the string word to search for
 * @return a SearchResult object that contains the index at which the DictEntry was found and how many iterations it took
 */
SearchResult Dictionary::searchByWord(string word) {
    //throw an error if the list isn't sorted
    if (!this->isSorted()) throw runtime_error("cannot search an unsorted dictionary");

    //keep track of how many iterations the search took; this will also give us our index
    unsigned int count = 0;

    //for each item front to back,
    list<DictEntry>::iterator it = this->entries.begin();
    while (it != this->entries.end()) {
        //increase the count be one
        count++;

        //if we found what we are searching for, return it
        if (it->getWord() == word) return SearchResult(count - 1, count);

        //if not, go to the next item
        it++;
    }

    return SearchResult(-1, count);
};

/**
 * searchByWordReverse()
 *
 * searches this dictionary from back to front in search of a DictEntry object for which
 *  the word matches word
 *
 * @param word the string word to search for
 * @return a SearchResult object that contains the index at which the DictEntry was found and how many iterations it took
 */
SearchResult Dictionary::searchByWordReverse(string word) {
    //throw an error if the list isn't sorted
    if (!this->isSorted()) throw runtime_error("cannot reverse search an unsorted dictionary");

    //keep track of how many iterations the search took; this will also give us our index
    unsigned int count = 0;

    //for each item back to front,
    list<DictEntry>::reverse_iterator it = this->entries.rbegin();
    while (it != this->entries.rend()) {
        //increase the count be one
        count++;

        //if we found what we are searching for, return it
        if (it->getWord() == word) return SearchResult(this->entries.size() - count, count);

        //if not, go to the next item
        it++;
    }

    return SearchResult(-1, count);
};

/**
 * &operator>>
 *
 * reads a dictionary from an input stream (which is usally dictionary.txt)
 *
 * @param in input stream to read from (usually ifstream)
 * @param dict the dictionary object to read into
 * @return the input stream in
 */
istream &operator>>(istream &in, Dictionary &dict) {
    //while we can read words,
    string word;
    while (getline(in, word)) {
        //Read a word from the input stream and create a DictEntt
        DictEntry entry;
        entry.setWord(word);

        dict.push_back(entry);
    }

    //return in
    return in;
}

/**
 * &operator<<
 *
 * prints the dictionary to an output stream from back to front
 *
 * @param out the output stream to which this dictionary will be printed (ex: ofstream to "revsorted.txt")
 * @param dict the dictionary object to print to the output stream
 * @return the output stream out
 */
ostream &operator<<(ostream &out, Dictionary &dict) {
    //for each entry from back to front,
    for (list<DictEntry>::reverse_iterator it = dict.entries.rbegin(); it != dict.entries.rend(); it++) {
        //output the word the entry contains
        out << it->getWord() << endl;
    }

    //return out
    return out;
}