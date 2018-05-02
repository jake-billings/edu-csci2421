//
// Created by Jake Billings on 5/2/18.
//
#include <iostream>
#include <unordered_map>

#include "Node.h"

using namespace std;

#ifndef EDU_CSCI2421_OPERATORS_H
#define EDU_CSCI2421_OPERATORS_H

ostream &operator<< (ostream &out, unordered_map<string, string> row);

ostream &operator<< (ostream &out, const GeneralData &data);

#endif //EDU_CSCI2421_OPERATORS_H
