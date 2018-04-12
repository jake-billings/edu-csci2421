//
// Created by Jake Billings on 4/11/18.
//


#include<string>

using namespace std;

#ifndef EDU_CSCI2421_RECORD_H
#define EDU_CSCI2421_RECORD_H

/**
 * Row
 *
 * class
 *
 * A row represents one "Record" in one "Table" of the database.
 *  A row contains a set of cells that map property names to property values to form objects
 *  (kind of like JavaScript objects)
 */
class Row {
private:
    vector<Cell> cells;
public:
    string getValue(string name);
    string setValue(string name, string value);
};


#endif //EDU_CSCI2421_RECORD_H
