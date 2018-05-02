/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: declaration file for Table class
 * Status: compiles and runs on csegrid
 */
#include <vector>
#include <unordered_map>

#include "BSTree.hpp"
#include "csv.h"

using namespace std;

#ifndef EDU_CSCI2421_TABLE_H
#define EDU_CSCI2421_TABLE_H

/**
 * Table
 *
 * class
 *
 * data structure
 *
 * trade off: high memory usage for quick access times
 *
 * a "Table" is essentially an unorderd map of binary search trees of unordered maps
 *
 * the innermost unordered maps are inspired by javascript objects and can be thought of as rows
 * each binary search tree is sorted by a different key (a.k.a column name) from each row
 * the outermost unordered map connects BSTs with the keys for which they are sorted
 *
 * to access data:
 *  1. pick a key to search by -> this picks a BST from the outermost unorderedMap
 *  2. pick a value to search for -> this retreives an item out of the BST
 *
 * the constructor builds all of the trees and maps; it performs multiple sorts and may
 *  impede performance; however, subsequent reads are much faster
 *
 * I make use of many inefficient string copies to get this prototype to work; however, I didn't
 *  feel like messing with the pointers at this point in this project.
 */
class Table {
private:
    /**
     * titles
     *
     * vector<string>
     *
     * list of all "indexes" or "titles" in this table
     *  this is essentially the header row of the csv file
     *  all of the "column names"
     */
    vector<string> titles;

    /**
     * rawData
     *
     * vector<unordered_map<string, string>>
     *
     * this is the unsorted list of javascript-like objects from the constructor
     *  this has been sorted into BSTs for each field
     *
     *  all unordered maps must have the same keys
     *  these keys must be the values from "titles"
     */
    vector<unordered_map<string, string>> rawData;

    /**
     * indexedData
     *
     * unordered_map<string, BSTree<unordered_map<string, string>, string>*>
     *
     * this is the main data structure as described in the class docs
     *
     * this is an unordered map linking each "title"/"column name" to a BST that is sorted by that value
     */
    unordered_map<string, BSTree<unordered_map<string, string>, string>*> indexedData;
public:
    /**
     * Table
     *
     * constructor
     *
     * empty constructor
     *
     * available if you need to declare something outside a try/catch or something
     *  don't use this to instantiate an empty table; you need data first
     */
    Table() {}

    /**
     * Table
     *
     * constructor
     *
     * intended for use with "readCsvAsMaps()"
     * builds the sorted table data structure as desribe in class description
     *
     * @param titles the column names from the top of the CSV to create indices; the things to sort by
     * @param rawData rows of the table represented as maps (like javascript objects) where column names link to values
     */
    Table(vector<string> titles, vector<unordered_map<string, string>> rawData);

    /**
     * findByValue()
     *
     * method
     *
     * search for and return a row from the table by selecting a BST sorted by "columnValue" then searching it for "cellValue"
     *
     * throws runtime_error if there's no match
     *
     * @param columnValue the column value to search within (and BST to select)
     * @param cellValue the cell value to search for
     * @return the complete row object as an unordered_map
     */
    unordered_map<string, string> findByValue(string columnValue, string cellValue);

    /**
     * findByPartialValue()
     *
     * method
     *
     * search for a row by searching for an exact match on a field
     *
     * throws runtime_error if there's no match
     *
     * @param columnValue the name of the column to search for; the search index to use
     * @param cellValue the value to search for; this is what must match
     * @return a complete row matching the exact field/column combination
     */
    unordered_map<string, string> findByPartialValue(string columnValue, string cellValue);

    /**
     * removeByValue()
     *
     * method
     *
     * delete a row by searching for an exact match on a field
     *
     * throws runtime_error if there's no match
     *
     * @param columnValue the name of the column to search for; the search index to use
     * @param cellValue the value to search for; this is what must match
     */
    void removeByValue(string columnValue, string cellValue);

    /**
     * replaceByValue()
     *
     * method
     *
     * delete a row by searching for an exact match on a field then replace it with a new one
     *
     * throws runtime_error if there's no match
     *
     * @param columnValue the name of the column to search for; the search index to use
     * @param cellValue the value to search for; this is what must match
     */
    void replaceByValue(string columnValue, string cellValue,unordered_map<string, string> row);

    /**
     * printInOrderBy()
     *
     * method
     *
     * calls printInorder() on the BST sorted by "key"
     *
     * throws runtime_error if theres no column by that name
     *
     * @param key to column name to order by
     */
    void printInOrderBy(string key);

    /**
     * add()
     *
     * method
     *
     * insert a single row into the table
     *
     * @param row the row to insert
     */
    void add(unordered_map<string, string> row);

    /**
     * getTitles()
     *
     * method
     *
     * returns the titles for this table (from the top row of csv)
     *
     * @return vector of titles
     */
    const vector<string> &getTitles() const;

};

/**
 * readTable()
 *
 * method
 *
 * read a table from a CSV input stream
 *
 * uses csv util
 *
 * throws runtime_error if anything goes wrong (e.g. formatting)
 *
 * @param in input stream pointed at a valid csv file
 * @return a table object based on the csv
 */
Table readTable(istream &in);

#endif //EDU_CSCI2421_TABLE_H
