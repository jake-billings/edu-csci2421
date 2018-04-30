//
// Created by Jake Billings on 4/30/18.
//

#include "csv.h"

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
vector<map<string, string>> readCsvAsMaps(istream &in) {
    //---Titles---
    //Reading the titles is a special case; the first row isn't treated the same as the other rows
    //1. Read the whole title line
    vector<string> titles;
    string titleLine;
    getline(in, titleLine);

    //2. Read each comma-separated value within that title line as a single title
    istringstream titleStream(titleLine);
    do {
        string title;
        getline(titleStream, title, ',');
        titles.push_back(title);
    } while (!titleStream.eof());

    //Instantiate the table object we're going to return
    vector<map<string, string>> table;


    //---Rows---
    while (!in.eof()) {
        // 1. Read the entire row
        string line;
        getline(in, line);
        istringstream lineStream(line);

        // 2. Instantiate a map to store the row's contents (this is the part inspired by JSON objects)
        map<string, string> row;

        // 3. Read each comma-separated value within that row as a single field value where the key is given by the column header
        unsigned int i = 0;
        do {
            string cell;
            getline(lineStream, cell, ',');

            if (i >= titles.size()) {
                throw runtime_error("malformed csv; row length exceeded column row length");
            }
            row[titles[i]] = cell;
            i++;
        } while (!lineStream.eof());

        table.push_back(row);
    }

    return table;
};