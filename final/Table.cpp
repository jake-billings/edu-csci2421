/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: implementation file for Table class
 * Status: compiles and runs on csegrid
 */

#include "Table.h"

/**
 * Table
 *
 * constructor
 *
 * intended for use with "readCsvAsMaps()"
 * builds the sorted table data structure as desribe in class description
 *
 * @param titles the column names from the top of the CSV to create indices; the things to sort by
 * @param rawData rows of the table represented as maps (like javascript objects) where column names link to values
 */
Table::Table(vector<string> titles, vector<unordered_map<string, string>> rawData) : titles(titles),
                                                                                     rawData(rawData) {
    for (unsigned int i = 0; i < titles.size(); i++) {
        string titleToIndex = this->titles[i];
        auto *tree = new BSTree<unordered_map<string, string>, string>();
        for (unsigned int j = 0; j < rawData.size(); j++) {
            unordered_map<string, string> row = this->rawData[j];
            string key = row[titleToIndex];
            tree->addNode(key, row);
        }
        this->indexedData[titles[i]] = tree;
    }
}

/**
 * findByValue()
 *
 * method
 *
 * search for and return a row from the table by selecting a BST sorted by "columnValue" then searching it for "cellValue"
 *
 * throws runtime_error if there's no match
 *
 * @param columnValue the column value to search within (and BST to select)
 * @param cellValue the cell value to search for
 * @return the complete row object as an unordered_map
 */
unordered_map<string, string> Table::findByValue(string columnValue, string cellValue) {
    BSTree<unordered_map<string, string>, string> *t = this->indexedData[columnValue];
    if (t == nullptr) {
        throw runtime_error("no index on that column");
    }
    Node<unordered_map<string, string>, string> *n = t->findNode(cellValue);
    if (n != nullptr) return n->Data();
    throw runtime_error("no object found with that key/field combination");
};

/**
 * findByPartialValue()
 *
 * method
 *
 * search for a row by searching for an exact match on a field
 *
 * throws runtime_error if there's no match
 *
 * @param columnValue the name of the column to search for; the search index to use
 * @param cellValue the value to search for; this is what must match
 * @return a complete row matching the exact field/column combination
 */
unordered_map<string, string> Table::findByPartialValue(string columnValue, string cellValue) {
    for (unsigned int i = 0; i<rawData.size(); i++) {
        unordered_map<string, string> row = this->rawData[i];
        if (row[columnValue].find(cellValue) !=  string::npos) {
            return row;
        }
    }
    throw runtime_error("no object found with that partial key/field combination");
};

/**
 * removeByValue()
 *
 * method
 *
 * delete a row by searching for an exact match on a field
 *
 * throws runtime_error if there's no match
 *
 * @param columnValue the name of the column to search for; the search index to use
 * @param cellValue the value to search for; this is what must match
 */
void Table::removeByValue(string columnValue, string cellValue) {
    BSTree<unordered_map<string, string>, string> *t = this->indexedData[columnValue];
    if (t == nullptr) throw runtime_error("no index on that column");
    Node<unordered_map<string, string>, string> *n = t->findNode(cellValue);
    if (n == nullptr) throw runtime_error("no object found with that key/field combination");

    unordered_map<string, string> row = n->Data();

    for (unsigned int i = 0; i < titles.size(); i++) {
        string titleToIndex = this->titles[i];

        BSTree<unordered_map<string, string>, string> *t = this->indexedData[titleToIndex];

        string key = row[titleToIndex];
        t->deleteNode(key);
    }
};

/**
 * replaceByValue()
 *
 * method
 *
 * delete a row by searching for an exact match on a field then replace it with a new one
 *
 * throws runtime_error if there's no match
 *
 * @param columnValue the name of the column to search for; the search index to use
 * @param cellValue the value to search for; this is what must match
 */
void Table::replaceByValue(string columnValue, string cellValue,unordered_map<string, string> row) {
    this->removeByValue(columnValue, cellValue);
    this->add(row);
}

/**
 * printInOrderBy()
 *
 * method
 *
 * calls printInorder() on the BST sorted by "key"
 *
 * throws runtime_error if theres no column by that name
 *
 * @param key to column name to order by
 */
void Table::printInOrderBy(string key) {
    this->indexedData[key]->printInorder();
}

/**
 * add()
 *
 * method
 *
 * insert a single row into the table
 *
 * @param row the row to insert
 */
void Table::add(unordered_map<string, string> row) {
    for (unsigned int i = 0; i < titles.size(); i++) {
        string titleToIndex = this->titles[i];
        if (row.find(titleToIndex) == row.end()) {
            throw runtime_error("cannot add row to table; it is missing columns");
        }
    }
    rawData.push_back(row);
    for (unsigned int i = 0; i < titles.size(); i++) {
        string titleToIndex = this->titles[i];

        BSTree<unordered_map<string, string>, string> *t = this->indexedData[titleToIndex];
        if (t == nullptr) throw runtime_error("no index on that column");

        string key = row[titleToIndex];
        t->addNode(key, row);
    }
}

/**
 * getTitles()
 *
 * method
 *
 * returns the titles for this table (from the top row of csv)
 *
 * @return vector of titles
 */
const vector<string> &Table::getTitles() const {
    return titles;
}

/**
 * readTable()
 *
 * method
 *
 * read a table from a CSV input stream
 *
 * uses csv util
 *
 * throws runtime_error if anything goes wrong (e.g. formatting)
 *
 * @param in input stream pointed at a valid csv file
 * @return a table object based on the csv
 */
Table readTable(istream &in) {
    pair<vector<string>, vector<unordered_map<string, string>>> result = readCsvAsMaps(in);
    vector<string> titles = result.first;
    vector<unordered_map<string, string>> table = result.second;

    return Table(titles, table);
}