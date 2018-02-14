/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description: function definitions for sorting and searching vectors of Vehicle classes
 * Status: compiles and runs on csegrid
 */

//Include vector because we need it for search/sort
#include <vector>
//Incude std except because we need runtime_err
#include <stdexcept>
//Include Vehicle because all of these functions depend on it
#include "Vehicle.h"

#ifndef EDU_CSCI2421_FUNCTIONS_H
#define EDU_CSCI2421_FUNCTIONS_H

/**
 * sortByMake()
 *
 * MUTATES the vector referenced by inventoryPtr
 *
 * performs an in-place bubble sort on the vector referenced by inventoryPtr in ASCENDING order
 *  with respect to make
 *
 * the c++ implementation of string ordering is alphabetization, so this function alphabetizes by
 *  make
 *
 * @param inventoryPtr a pointer to the vehicle array that we are trying to sort
 */
void sortByMake(vector<Vehicle> *inventoryPtr);

/**
 * sortByModel()
 *
 * MUTATES the vector referenced by inventoryPtr
 *
 * performs an in-place bubble sort on the vector referenced by inventoryPtr in ASCENDING order
 *  with respect to model
 *
 * the c++ implementation of string ordering is alphabetization, so this function alphabetizes by
 *  model
 *
 * @param inventoryPtr a pointer to the vehicle array that we are trying to sort
 */
void sortByModel(vector<Vehicle> *inventoryPtr);

/**
 * sortByYear()
 *
 * MUTATES the vector referenced by inventoryPtr
 *
 * performs an in-place bubble sort on the vector referenced by inventoryPtr in ASCENDING order
 *  with respect to year
 *
 * @param inventoryPtr a pointer to the vehicle array that we are trying to sort
 */
void sortByYear(vector<Vehicle> *inventoryPtr);

/**
 * _binSearchRecYear()
 *
 * Performs the recursion in a recursive binary search
 *
 * PRIVATE: this is not the exposed implementation of binary search. This is the recursive portion of binary search
 *  only. It is called by the public exposed binSearchRecYear()
 *
 * With the proper init paramters, this function will perform a binary search. See binSearchRecYear() for those
 *  starting parameters.
 *
 * This function assumes the inventor vector is sorted.
 *
 * @private
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @param left the left side of the search region for this iteration
 * @param right the right side of the search region for this iteration
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *binSearchRecYear(vector<Vehicle> *inventoryPtr, unsigned int year);

/**
 * binSearchRecYear()
 *
 * Performs a recursive binary search for a vehicle with a given year in a SORTED vector of vehicles
 *
 * This function checks that the inventor vector is sorted in ASCENDING order. If it isn't, we throw a runtime_error.
 *
 * validates and sets init params then calls _binSearchRecYear()
 *
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *binSearchIterYear(vector<Vehicle> *inventoryPtr, unsigned int year);

/**
 * binSearchIterYear()
 *
 * Performs an iterative binary search for a vehicle with a given year in a SORTED vector of vehicles
 *
 * This function checks that the inventor vector is sorted in ASCENDING order. If it isn't, we throw a runtime_error.
 *
 * validates and sets init params then iterates
 *
 * @param inventoryPtr pointer to a SORTED vector of vehicles through which we are sorting
 * @param year the target integer year we are searching for
 * @return pointer to a vehicle object if the search finds a result; nullptr if no result is found
 */
Vehicle *slowSearchYear(vector<Vehicle> *inventoryPtr, unsigned int year);

#endif //EDU_CSCI2421_FUNCTIONS_H
