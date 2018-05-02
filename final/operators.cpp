/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: implementation file for print operators for items that may be inserted into BSTs
 * Status: compiles and runs on csegrid
 */

#include "operators.h"

ostream &operator<<(ostream &out, unordered_map<string, string> row) {
    unordered_map<string, string>::iterator it = row.begin();

    while (it != row.end()) {
        out << it->first << ": " << it->second << endl;
        it++;
    }

    return out;
}

ostream &operator<<(ostream &out, const GeneralData &data) {
    out << data.number << "\t" << data.name << endl;
    return out;
}