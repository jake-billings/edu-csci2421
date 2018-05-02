/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: main.cpp contains the main function, which runs tests and starts the menu loop
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