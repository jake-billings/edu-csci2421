/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: declaration file for print operators for items that may be inserted into BSTs
 * Status: compiles and runs on csegrid
 */

#include <iostream>
#include <unordered_map>

#include "Node.h"

using namespace std;

#ifndef EDU_CSCI2421_OPERATORS_H
#define EDU_CSCI2421_OPERATORS_H

ostream &operator<< (ostream &out, unordered_map<string, string> row);

ostream &operator<< (ostream &out, const GeneralData &data);

#endif //EDU_CSCI2421_OPERATORS_H
