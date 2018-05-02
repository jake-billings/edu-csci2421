#include "test.h"

void fuzz_bst() {
    cout << "Fuzzing BST...";
    auto *fuzzy = new BSTree<int, int>();

    for (unsigned int i = 0; i < 100; i++) {
        int a = rand();
        int *j = new int(a);
        fuzzy->addNode(rand(), *j);
    }

    for (unsigned int i = 0; i < 10000; i++) {
        fuzzy->findNode(rand());
    }

    for (unsigned int i = 0; i < 10000; i++) {
        fuzzy->deleteNode(rand());
    }

    for (unsigned int i = 0; i < 100000; i++) {
        fuzzy->findNode(rand());
    }

    for (unsigned int i = 0; i < 10000; i++) {
        fuzzy->deleteNode(rand());
    }

    cout << "Done." << endl;

    delete fuzzy;
}

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
    cout << "========Other Tests========" << endl;
    fuzz_bst();
    cout << "======End Other Tests======" << endl;

    //Keep track of how many tests we fail
    unsigned int failCount = 0;

    //Print welcome message
    cout << "========Unit Tests========" << endl;

    //read the test csv file
    ifstream testCsvInputStream;
    testCsvInputStream.open("small.csv");
    pair<vector<string>, vector<unordered_map<string, string>>> result = readCsvAsMaps(testCsvInputStream);
    vector<string> titles = result.first;
    vector<unordered_map<string, string>> tableMap = result.second;
    testCsvInputStream.close();

    //---csv reader testing---
    describe("csv: readCsvAsMaps(): test table: should have three columns");
    failCount += assertInt(3, titles.size());
    describe("csv: readCsvAsMaps(): test table: should have second column named \"header2\"");
    failCount += assertString("header2", titles[1]);
    describe("csv: readCsvAsMaps(): test table: should have two rows");
    failCount += assertInt(2, tableMap.size());
    describe("csv: readCsvAsMaps(): test table: access on column 1 row 1 should return cell 1");
    failCount += assertString("cell1", tableMap[0]["header1"]);
    describe("csv: readCsvAsMaps(): test table: access on column 1 row 2 should return cell 4");
    failCount += assertString("cell4", tableMap[1]["header1"]);
    describe("csv: readCsvAsMaps(): test table: access on column 3 row 2 should return cell 6");
    failCount += assertString("cell6", tableMap[1]["header3"]);

    ostringstream rawCsvFileStream;
    ifstream testCsvInputStreamRaw;
    testCsvInputStreamRaw.open("small.csv");
    while (!testCsvInputStreamRaw.eof()) {
        string temp;
        getline(testCsvInputStreamRaw, temp);
        for (unsigned int i = 0; i < temp.size(); i++) {
            if (temp[i] == '"') {
                temp.replace(i, 1, "");
            }
        }
        rawCsvFileStream << temp << endl;
    }

    ostringstream outputtedTableStream;
    writeMapsAsCsv(outputtedTableStream, titles, tableMap);

    describe("csv: writeMapsAsCsv(): should output the exact same csv file (ignoring \"\"\")");
    failCount += assertString(rawCsvFileStream.str(), outputtedTableStream.str());

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

    describe(
            "BSTree<unordered_map<string, string>, string>: querying a node that does not exist should return nullptr");
    Node<unordered_map<string, string>, string> *foundNode = tree2->findNode(target);
    failCount += assertLong((long) nullptr, (long) foundNode);

    describe(
            "BSTree<unordered_map<string, string>, string>: querying a node that does exist should not return nullptr");
    string target2("numberone");
    foundNode = tree2->findNode(target2);
    failCount += assertNotNull((long) foundNode);

    describe(
            "BSTree<unordered_map<string, string>, string>: querying that node should return data and that data should have expected children");
    unordered_map<string, string> dataFromTree = foundNode->Data();
    failCount += assertString("b", dataFromTree["a"]);

    describe(
            "BSTree<unordered_map<string, string>, string>: querying that node should not return data from other children");
    failCount += assertString("", dataFromTree["asdf"]);

    delete s;
    delete tree;
    delete tree2;

    describe(
            "BSTree<unordered_map<string, string>, string>: querying that node should still work after deleting the tree");
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
    Table table3 = readTable(testCsvInputStream3);
    testCsvInputStream3.close();
    failCount += assertString("cell4", table3.findByValue("header2", "cell5")["header1"]);

    //----Requirements-Based Unit Testing----
    //Can we do each requirement in code?
    // If so, all we'd need is the menu system

    describe("R1/R2: Read information from provided csv files (without an exception)");

    ifstream actorStream;
    ifstream nominationStream;
    ifstream pictureStream;
    Table actors;
    Table nominations;
    Table pictures;

    err = false;
    try {
        actorStream.open("actor-actress.csv");
        actors = readTable(actorStream);
        actorStream.close();

        nominationStream.open("nominations.csv");
        nominations = readTable(nominationStream);
        nominationStream.close();

        pictureStream.open("pictures.csv");
        pictures = readTable(pictureStream);
        pictureStream.close();
    } catch (runtime_error e) {
        err = true;
        cout << e.what();
    }

    failCount += assertInt(false, err);

    describe("R3/R4: Choose either the movie or actor database and add a record (should fail if missing fields)");
    unordered_map<string, string> newActor;
    newActor["Year"] = "2019";
    newActor["Award"] = "Best movie ever";
    newActor["Winner"] = "1";
    newActor["Name"] = "Students";
    //missing "Film"
    err = false;
    try {
        actors.add(newActor);
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("R3/R4: Choose either the movie or actor database and add a record (should succeed with all fields)");
    newActor["Film"] = "Data Structures: The SQL";
    err = false;
    try {
        actors.add(newActor);
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(false, err);

    describe("R3/R4: Choose either the movie or actor database and add a record (should get row back)");
    failCount += assertString("Students", actors.findByValue("Year", "2019")["Name"]);

    describe("R7/R8: Choose either the movie or actor database, search for a record and delete the fields");
    actors.removeByValue("Year", "2019");
    err = false;
    try {
        actors.findByValue("Year", "2019");
    } catch (runtime_error e) {
        err = true;
    }
    failCount += assertInt(true, err);

    describe("R5/R6: : Choose either the movie or actor database, search for a record, and modify the fields");
    unordered_map<string, string> newActor2;
    newActor2["Year"] = "2020";
    newActor2["Award"] = "Best movie ever";
    newActor2["Winner"] = "1";
    newActor2["Name"] = "Students";
    newActor2["Film"] = "Data Structures: The SQL Part II";
    actors.add(newActor2);
    unordered_map<string, string> newActorFetched = actors.findByValue("Year", "2020");
    newActorFetched["Year"] = "2021";
    actors.replaceByValue("Year", "2020", newActorFetched);
    failCount += assertString("Students", actors.findByValue("Year", "2021")["Name"]);

    //R9/R10: Sorting: Due to BST implementation we received, this is not unit-testable without re-writing the code from the assignment
    //R11/R12: Complete Searching: already tested

    describe("R13/R14:  either the movie or the actor database and do a partial search on any searchable field");
    failCount += assertString("Students", actors.findByPartialValue("Film", "The SQL Part")["Name"]);

    //R15/R16: write out as CSV; CSV writing tested separately

    //----Test MenuSystem----
    //MenuSystem option 1
    istringstream mockInput;
    ostringstream mockOutput;
    MenuSystem menu(mockInput, mockOutput);

    describe("MenuSystem: option 1: should load defaults");
    mockInput.str("1");
    mockOutput.str("");
    bool menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 1: should not have error message");
    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 1: should have loaded the first row of the actor");

    unordered_map<string, Table> db = menu.getDb();
    Table t = db["actors"];
    string lookupVal = "Film";
    failCount += assertString("Emil Jannings", t.findByValue(lookupVal, "The Last Command")["Name"]);

    //MenuSystem option 2
    istringstream mockInput2;
    ostringstream mockOutput2;
    MenuSystem menu2(mockInput2, mockOutput2);

    describe("MenuSystem: option 2: should load custom");
    mockInput2.str("2\nactors\nactor-actress.csv\n");
    mockOutput2.str("");
    bool menuResult2 = menu2.rootMenu();
    failCount += assertInt(true, menuResult2);
    describe("MenuSystem: option 2: should not have error message");
    failCount += assertInt(true, mockOutput2.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 2: should have loaded the first row of the actor");
    unordered_map<string, Table> db2 = menu.getDb();
    Table t2 = db["actors"];
    string lookupVal2 = "Film";
    failCount += assertString("Emil Jannings", t.findByValue(lookupVal2, "The Last Command")["Name"]);

    //MenuSystem option 3
    describe("MenuSystem: option 3: should add new actor");
    mockInput.str("3\nactors\n2025\nTest Award\n1\nJake Billings\nTest Film\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 3: should not have error message");
    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 3: should have added a new actor");
    db = menu.getDb();
    t = db["actors"];
    failCount += assertString("Jake Billings", t.findByValue("Year", "2025")["Name"]);

    //MenuSystem option 4
    describe("MenuSystem: option 4: should find a record");
    mockInput.str("4\nactors\nYear\n2025\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 4: should not have error message");
    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 4: should have found correct entry");
    failCount += assertInt(false, mockOutput.str().find("Jake Billings") == string::npos);

    describe("MenuSystem: option 4: should gracefully not find a record");
    mockInput.str("4\nactors\nYear\n1243214\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 4: should have error message");
    failCount += assertInt(false, mockOutput.str().find("Sorry") == string::npos);

    //MenuSystem option 5
    describe("MenuSystem: option 5: should modify a record");
    mockInput.str("5\nactors\nYear\n2025\n2025\nTest Award\n1\nUpdated Version Name\nTest Film\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 5: should not have error message");
    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 5: should have found correct entry");
    db = menu.getDb();
    t = db["actors"];
    failCount += assertString("Updated Version Name", t.findByValue("Year", "2025")["Name"]);

    //MenuSystem option 6
    describe("MenuSystem: option 6: should delete a record");
    mockInput.str("6\nactors\nYear\n2025\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 6: should not have error message");
    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 6: should not find the deleted entry");
    db = menu.getDb();
    t = db["actors"];
    bool merr = false;
    try {
        t.findByValue("Year", "2025");
    } catch (runtime_error e) {
        merr = true;
    }
    failCount += assertInt(true, merr);

    //MenuSystem option 7
    //    describe("MenuSystem: option 7: should print in order");
    //    mockInput.str("7\nactors\nYear\n");
    //    mockOutput.str("");
    //    menuResult = menu.rootMenu();
    //    failCount += assertInt(true, menuResult);
    //    describe("MenuSystem: option 7: should not have error message");
    //    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    //can't actually test anything else because BSTtree has cout built in
    // and it's from the project, so we can't change it


    //MenuSystem option 8
    describe("MenuSystem: option 8: should find a record");
    mockInput.str("8\nactors\nName\nJannings\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 8: should not have error message");
    failCount += assertInt(true, mockOutput.str().find("Sorry") == string::npos);
    describe("MenuSystem: option 8: should have found correct entry");
    failCount += assertInt(false, mockOutput.str().find("The Last Command") == string::npos);

    describe("MenuSystem: option 8: should gracefully not find a record");
    mockInput.str("8\nactors\nYear\n1243214\n");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(true, menuResult);
    describe("MenuSystem: option 8: should have error message");
    failCount += assertInt(false, mockOutput.str().find("Sorry") == string::npos);


    //MenuSystem option 9
    describe("MenuSystem: option 9: should exit");
    mockInput.str("9");
    mockOutput.str("");
    menuResult = menu.rootMenu();
    failCount += assertInt(false, menuResult);

    //Completion message
    cout << endl << "Completed automated tests. Failed " << failCount << " tests." << endl;
    cout << "======End Unit Tests======" << endl;

}