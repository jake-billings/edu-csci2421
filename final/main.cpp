/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: main.cpp contains the main function, which runs tests and starts the menu loop
 *
 * Final Project
 * =============
 *
 * Task: Implement a database using any data structures you want; although, using a binary search tree is required.
 *  It was also required to use some provided files for the binary search tree.
 *
 * I implement the database as an unordered map of unordered maps of binary search trees of unordered maps
 *  Layer 1: Table: the data shape/type Key: Table Name (E.g. Actors, Nominations)
 *  Layer 2: Index: the pre-sort column of the binary tree Key: Column Name (E.g. Name)
 *  Layer 3: BST: the sorted BST for a given column name Key: Cell Value Name (E.g. John Smith)
 *  Layer 4: object/row inspired by javascript objects Key: Column Name (E.g. Name)
 *
 * Any exact, single-element lookup should return in Avg: O(1) * O(1) * O(log(n)) * O(1) = O(log(n))
 *  This could theoretically be more efficient if the BST was replaced with another unordered map; however,
 *  we would lose sort indexing, and the project requirement of having a BST.
 *
 * I perform Unit, Integration, and E2E styles of testing in test() in test.cpp. This verifies the functionality
 *  of the database software and of the UI.
 *
 *  Extra Credit
 *  ============
 *  Task: include an additional CSV file and interesting statistics
 *
 *  I only included nominations.csv into the project. All nominations can be viewed, edited, etc. just like the other
 *  files.
 *
 *  I did not implement statistics.
 *
 * Status: compiles and runs on csegrid
 */
#include "test.h"
#include "MenuSystem.h"

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Run unit tests
    test();

    //Start the menu system
    MenuSystem menu(cin, cout);
    menu.loop();

    //Return a nominal status code
    return 0;
}