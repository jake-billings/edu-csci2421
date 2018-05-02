//
// Created by Jake Billings on 4/30/18.
//

#include "Table.h"

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

unordered_map<string, string> Table::findByValue(string columnValue, string cellValue) {
    BSTree<unordered_map<string, string>, string> *t = this->indexedData[columnValue];
    if (t == nullptr) throw runtime_error("no index on that column");
    Node<unordered_map<string, string>, string> *n = t->findNode(cellValue);
    if (n != nullptr) return n->Data();
    throw runtime_error("no object found with that key/field combination");
};

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

void Table::replaceByValue(string columnValue, string cellValue,unordered_map<string, string> row) {
    this->removeByValue("Year", "2020");
    this->add(row);
}


void Table::printInOrderBy(string key) {
    this->indexedData[key]->printInorder();
}

void Table::add(unordered_map<string, string> row) {
    for (unsigned int i = 0; i < titles.size(); i++) {
        string titleToIndex = this->titles[i];
        if (row.find(titleToIndex) == row.end()) {
            throw runtime_error("cannot add row to table; it is missing columns");
        }
    }
    for (unsigned int i = 0; i < titles.size(); i++) {
        string titleToIndex = this->titles[i];

        BSTree<unordered_map<string, string>, string> *t = this->indexedData[titleToIndex];
        if (t == nullptr) throw runtime_error("no index on that column");

        string key = row[titleToIndex];
        t->addNode(key, row);
    }
}

Table readTable(istream &in) {
    pair<vector<string>, vector<unordered_map<string, string>>> result = readCsvAsMaps(in);
    vector<string> titles = result.first;
    vector<unordered_map<string, string>> table = result.second;

    return Table(titles, table);
}