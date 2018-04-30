/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "test.h"

/**
 * int test()
 *
 * Tests the functionality of the union operators; logs errors to the console if they exist
 */
void test() {
    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //Print welcome message
    cout << "========Unit Tests========" << endl;

    ifstream testCsvInputStream;
    testCsvInputStream.open("small.csv");
    vector<map<string, string>> table = readCsvAsMaps(testCsvInputStream);

    //---csv reader testing---
    describe("csv: test table: should have two rows");
    failCount += assertInt(2, table.size());
    describe("csv: test table: access on column 1 row 1 should return cell 1");
    failCount += assertString("cell1", table[0]["header1"]);
    describe("csv: test table: access on column 1 row 2 should return cell 4");
    failCount += assertString("cell4", table[1]["header1"]);
    describe("csv: test table: access on column 3 row 2 should return cell 6");
    failCount += assertString("cell6", table[1]["header3"]);

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Tests======" << endl;

}