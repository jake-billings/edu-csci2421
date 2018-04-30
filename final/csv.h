//
// Created by Jake Billings on 4/30/18.
//
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

#ifndef EDU_CSCI2421_CSV_H
#define EDU_CSCI2421_CSV_H

/**
 * readCsvAsMaps()
 *
 * inspired by JSON/JavaScript objects
 *
 * reads every row of a csv file as a map object where the keys are the header cells and
 *  the cells are field values
 *
 * assumes istream is an input stream pointing to a valid csv file with a single header row that is as wide
 *  as data
 *
 * may throw runtime_error if csv is malformed
 *
 * @param in input stream pointing to a valid csv file
 * @return a vector in which each entry is a map representing the row from the csv
 */
vector <map<string, string>> readCsvAsMaps(istream &in);

#endif //EDU_CSCI2421_CSV_H
