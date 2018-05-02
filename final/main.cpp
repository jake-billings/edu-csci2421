#include <iostream>

#include "MenuSystem.h"
#include "test.h"

//-----------Main Function------------
/**
 * int main()
 *
 * The main entry point for the application.
 *
 * Returns 0.
 */
int main() {
    //Run Unit tests
    test();

    MenuSystem menu(cin, cout);
    menu.loop();

    return 0;
}