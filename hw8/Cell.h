//
// Created by Jake Billings on 4/11/18.
//

#include<string>

using namespace std;

#ifndef EDU_CSCI2421_FIELD_H
#define EDU_CSCI2421_FIELD_H


/**
 * Cell
 *
 * class
 *
 * A cell represents one value for one field in one row of the table
 *  cells allow us to generalize query logic (kind of like JavaScript objects)
 */
class Cell {
private:
    string columnName;
    string value;
};


#endif //EDU_CSCI2421_FIELD_H
