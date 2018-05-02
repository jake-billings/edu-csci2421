/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: declaration file for MenuSystem class
 * Status: compiles and runs on csegrid
 */
#include <unordered_map>
#include <iostream>
#include <fstream>
#include "Table.h"

using namespace std;

#ifndef EDU_CSCI2421_MENUSYSTEM_H
#define EDU_CSCI2421_MENUSYSTEM_H


/**
 * MenuSystem
 *
 * class
 *
 * represents a menu system with a pair of input/output streams
 *  in/out are abstracted in order to allow for E2E testing using sstreams
 */
class MenuSystem {
private:
    /**
     * in
     *
     * istream&
     *
     * the input stream to read menu commands from
     *
     * Ex: cin
     */
    istream &in;

    /**
     * out
     *
     * ostream&
     *
     * the inoutput stream to write menu messages to
     *
     * Ex: cout
     */
    ostream &out;

    /**
     * db
     *
     * unordered_map<string, Table>
     *
     * map of table names to tables; all of the data we know about
     */
    unordered_map<string, Table> db;

    /**
     * tableNames
     *
     * vector<string>
     *
     * initialized in constructor; these are the valid values for answers to
     *  "which table?"
     * these are the keys to the map "db"
     */
    vector<string> tableNames;
public:
    /**
     * MenuSystem
     *
     * constructor
     */
    MenuSystem(istream &in, ostream &out);

    /**
     * rootMenu()
     *
     * method
     *
     * this would be private; however, it is used in unit testing
     *
     * @returns a boolean that is true if the main loop should continue (return is false if the menu should stop)
     */
    bool rootMenu();

    /**
     * loop()
     *
     * method
     *
     * execute rootMenu() until it tells us to quit
     */
    void loop();

    /**
     * loadTableFromPath()
     *
     * method
     *
     * implementation of options 1 and 2
     *
     * sets a map value in this->db to the contents of a new CSV file
     *
     * @param name the table name
     * @param path the path to load from
     */
    void loadTableFromPath(string name, string path);

    string selectTable();
    void printRow(vector<string> titles, unordered_map<string,string> row);

    const unordered_map<string, Table> &getDb() const;

    void menuOneLoadFromDefaults();
    void menuTwoLoad();
    void menuThreeAdd();
    void menuFourFind();
    void menuFiveModify();
    void menuSixDelete();
    void menuSevenSort();
    void menuEightPartialSearch();
};


#endif //EDU_CSCI2421_MENUSYSTEM_H
