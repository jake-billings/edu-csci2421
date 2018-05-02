/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "test.h"

/**
 * test_bst()
 *
 * specifically replaces BSTDriver.cpp with unit testing in my format
 *  does not fully test BST (see test())
 *
 * @return the failcount of BSTDriver tests
 */
int test_bst() {
    //failCount for bst tests
    unsigned int failCount = 0;

    //create the tree to test
    BSTree<GeneralData, int> *tree = new BSTree<GeneralData, int>;

    describe("bst: should store a single node");
    GeneralData tempData;
    tempData.number = 10;
    tempData.name = "Gamma";
    tree->addNode(tempData.number, tempData);
    failCount += assertString("Gamma", tree->findNode(10)->Data().name);

    tempData.number = 5;
    tempData.name = "Gamma";
    tree->addNode(tempData.number, tempData);

    tempData.number = 1;
    tempData.name = "Alpha";
    tree->addNode(tempData.number, tempData);

    tempData.number = 20;
    tempData.name = "Delta";
    tree->addNode(tempData.number, tempData);

    tempData.number = 30;
    tempData.name = "Eta";
    tree->addNode(tempData.number, tempData);

    tempData.number = 25;
    tempData.name = "Epsilon";
    tree->addNode(tempData.number, tempData);

    tempData.number = 2;
    tempData.name = "Beta";
    tree->addNode(tempData.number, tempData);


    describe("bst: should store additional node");
    failCount += assertString("Epsilon", tree->findNode(25)->Data().name);

    describe("bst: should not have a node we never stored");
    failCount += assertLong((long) nullptr, (long) tree->findNode(26));

    describe("bst: should not have nodes we deleted");
    tree->deleteNode(1);
    tree->deleteNode(10);
    tree->deleteNode(25);
    tree->deleteNode(2);
    tree->deleteNode(5);
    tree->deleteNode(20);
    tree->deleteNode(30);

    failCount += assertLong((long) nullptr, (long) tree->findNode(10));

    delete tree;

    return failCount;
}

/**
 * int test()
 *
 * Tests the functionality
 */
void test() {
    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //Print welcome message
    cout << "========Unit Tests========" << endl;

    //read the test csv file
    ifstream testCsvInputStream;
    testCsvInputStream.open("small.csv");
    pair<vector<string>, vector<unordered_map<string, string>>> result = readCsvAsMaps(testCsvInputStream);
    vector<string> titles = result.first;
    vector<unordered_map<string, string>>tableMap = result.second;
    testCsvInputStream.close();

    //---csv reader testing---
    describe("csv: test table: should have three columns");
    failCount += assertInt(3, titles.size());
    describe("csv: test table: should have second column named \"header2\"");
    failCount += assertString("header2", titles[1]);
    describe("csv: test table: should have two rows");
    failCount += assertInt(2, tableMap.size());
    describe("csv: test table: access on column 1 row 1 should return cell 1");
    failCount += assertString("cell1", tableMap[0]["header1"]);
    describe("csv: test table: access on column 1 row 2 should return cell 4");
    failCount += assertString("cell4", tableMap[1]["header1"]);
    describe("csv: test table: access on column 3 row 2 should return cell 6");
    failCount += assertString("cell6", tableMap[1]["header3"]);

    //---test BST---
    failCount += test_bst();

    //---test string BST---
    BSTree<string, string> *tree = new BSTree<string, string>;
    describe("BSTree<string, string>: should return nullptr for calls to empty tree");
    failCount += assertLong((long) nullptr, (long) tree->findNode("asdf"));
    describe("BSTree<string, string>: should return value for calls to tree with an element added");
    string *s = new string("qwerty");
    tree->addNode("asdf", *s);
    failCount += assertString("qwerty", tree->findNode("asdf")->Data());

    //---Test unordered map BST---
    unordered_map<string, string> m;
    m["a"] = "b";
    m["c"] = "d";
    unordered_map<string, string> m2;
    m2["asdf"] = "qwerty";
    m2["asdf2"] = "qwerty2";
    BSTree<unordered_map<string, string>, string> *tree2 = new BSTree<unordered_map<string, string>, string>;
    tree2->addNode("numberone", m);
    tree2->addNode("second node", m2);

    string target("asdf");

    describe("BSTree<unordered_map<string, string>, string>: querying a node that does not exist should return nullptr");
    Node<unordered_map<string, string>, string> *foundNode = tree2->findNode(target);
    failCount += assertLong((long) nullptr, (long) foundNode);

    describe("BSTree<unordered_map<string, string>, string>: querying a node that does exist should not return nullptr");
    string target2("numberone");
    foundNode = tree2->findNode(target2);
    failCount += assertNotNull((long) foundNode);

    describe("BSTree<unordered_map<string, string>, string>: querying that node should return data and that data should have expected children");
    unordered_map<string, string> dataFromTree = foundNode->Data();
    failCount += assertString("b", dataFromTree["a"]);

    describe("BSTree<unordered_map<string, string>, string>: querying that node should not return data from other children");
    failCount += assertString("", dataFromTree["asdf"]);

    delete s;
    delete tree;
    delete tree2;

    describe("BSTree<unordered_map<string, string>, string>: querying that node should still work after deleting the tree");
    failCount += assertString("b", dataFromTree["a"]);

    //---test Table---
    ifstream testCsvInputStream2;
    testCsvInputStream2.open("small.csv");
    Table table = readTable(testCsvInputStream2);
    testCsvInputStream2.close();

    describe("Table: findByValue(): header3, cell3");
    string a("header3");
    string b("cell3");
    unordered_map<string, string> result2 = table.findByValue(a, b);
    failCount += assertString("cell1", result2["header1"]);

    describe("Table: findByValue(): header3, cell6");
    unordered_map<string, string> result3 = table.findByValue("header3", "cell6");
    failCount += assertString("cell4", result3["header1"]);

    describe("Table: findByValue(): header1, cell1");
    unordered_map<string, string> result4 = table.findByValue("header1", "cell1");
    failCount += assertString("cell2", result4["header2"]);

    describe("Table: findByValue(): nonexistant header");
    bool err = false;
    try {
        table.findByValue("header1", "doesntmatterkey");
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("Table: findByValue(): real header nonexistant field");
    err = false;
    try {
        table.findByValue("non_existant_header", "non_exisitant_key");
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("integration: Table+csv: should successfully find row 2 using cell5 and header2");
    ifstream testCsvInputStream3;
    testCsvInputStream3.open("small.csv");
    pair<vector<string>, vector<unordered_map<string, string>>> csvPair = readCsvAsMaps(testCsvInputStream3);
    vector<string> titles3 = csvPair.first;
    vector<unordered_map<string, string>>tableMap3 = csvPair.second;
    testCsvInputStream3.close();
    Table table3 = Table(titles3, tableMap3);
    failCount += assertString("cell4", table3.findByValue("header2", "cell5")["header1"]);

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Tests======" << endl;

}