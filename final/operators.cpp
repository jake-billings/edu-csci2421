//
// Created by Jake Billings on 5/2/18.
//

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