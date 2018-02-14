/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description: function definitions for sorting and searching vectors of Vehicle classes
 * Status: compiles and runs on csegrid
 */

#include <vector>
//Incude std except because we need runtime_err
#include <stdexcept>
#include "Vehicle.h"

#ifndef EDU_CSCI2421_FUNCTIONS_H
#define EDU_CSCI2421_FUNCTIONS_H

void sortByMake(vector<Vehicle> *inventoryPtr);
void sortByModel(vector<Vehicle> *inventoryPtr);
void sortByYear(vector<Vehicle> *inventoryPtr);
Vehicle *binSearchRecYear(vector<Vehicle> *inventoryPtr, unsigned int year);
Vehicle *binSearchIterYear(vector<Vehicle> *inventoryPtr, unsigned int year);
Vehicle *slowSearchYear(vector<Vehicle> *inventoryPtr, unsigned int year);

#endif //EDU_CSCI2421_FUNCTIONS_H
