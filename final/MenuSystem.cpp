/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: implementation file for MenuSystem class
 * Status: compiles and runs on csegrid
 */

#include "MenuSystem.h"

/**
 * MenuSystem
 *
 * constructor
 */
MenuSystem::MenuSystem(istream &in, ostream &out) : in(in), out(out) {
    this->tableNames.push_back("actors");
    this->tableNames.push_back("pictures");
    this->tableNames.push_back("nominations");
}

/**
 * rootMenu()
 *
 * method
 *
 * @returns a boolean that is true if the main loop should continue (return is false if the menu should stop)
 */
bool MenuSystem::rootMenu() {
    this->out << "===================Menu System===================" << endl;
    this->out << "Make sure to use option 1 or option 2 to loadbefore attempting to view/modify data." << endl;
    this->out << "1. Load from defualt CSV files" << endl;
    this->out << "2. Load from CSV file" << endl;
    this->out << "3. Add a record" << endl;
    this->out << "4. Find a record (by exact value)" << endl;
    this->out << "5. Modify a record" << endl;
    this->out << "6. Delete a record" << endl;
    this->out << "7. Sort records by field" << endl;
    this->out << "8. Search for a records (by partial match)" << endl;
    this->out << "9. Write to CSV file" << endl;
    this->out << "q. Exit" << endl;
    this->out << endl;
    this->out << "Select one of the options above using its number." << endl;
    this->out << "> ";

    char selection;
    this->in >> selection;

    switch (selection) {
        case '1':
            this->menuOneLoadFromDefaults();
            break;
        case '2':
            this->menuTwoLoad();
            break;
        case '3':
            this->menuThreeAdd();
            break;
        case '4':
            this->menuFourFind();
            break;
        case '5':
            this->menuFiveModify();
            break;
        case '6':
            this->menuSixDelete();
            break;
        case '7':
            this->menuSevenSort();
            break;
        case '8':
            this->menuEightPartialSearch();
            break;
        case '9':
            this->menuNineWrite();
            break;
        case 'q':
            this->out << "Now exiting. Have a nice day." << endl;
            return false;
        default:
            this->out << "Sorry. That selection (" << selection
                      << ") isn't valid. Please pick one of the numbers from the menu." << endl;
    }

    return true;
}

/**
 * loop()
 *
 * method
 *
 * execute rootMenu() until it tells us to quit
 */
void MenuSystem::loop() {
    while (rootMenu());
}


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
void MenuSystem::loadTableFromPath(string name, string path) {
    bool valid = false;
    for (unsigned int i = 0; i < this->tableNames.size(); i++) {
        if (tableNames[i] == name) valid = true;
    }
    if (!valid) {
        this->out << "Sorry, that's not a valid table to load." << endl;
        return;
    }

    try {
        ifstream in;
        in.open(path);
        db[name] = readTable(in);
        in.close();
    } catch (runtime_error e) {
        this->out << "Sorry, that file is not properly formatted." << endl;
        this->out << e.what();
    }
}

/**
 * selectTable()
 *
 * method
 *
 * uses in/out to prompt the user to select a table that we know about
 *
 * called by menu items
 *
 * @return string name of a valid table
 */
string MenuSystem::selectTable() {
    string name;
    bool valid = false;
    while (!valid) {
        this->out << "What table?" << endl;
        this->out << "Valid selections: ";
        for (unsigned int i = 0; i < this->tableNames.size(); i++) {
            this->out << tableNames[i];
            if (i < this->tableNames.size() - 1) this->out << ", ";
        }
        this->out << endl;
        this->out << "> ";
        getline(this->in, name);

        for (unsigned int i = 0; i < this->tableNames.size(); i++) {
            if (tableNames[i] == name) valid = true;
        }
    }
    return name;
}

/**
 * printRow()
 *
 * method
 *
 * prints a row object from a given table to the output stream
 *
 * called by menu items
 *
 * @param titles the titles of the items in the map to print
 * @param row the map to print
 */
void MenuSystem::printRow(vector<string> titles, unordered_map<string, string> row) {
    for (unsigned int i = 0; i < titles.size(); i++) {
        string title = titles[i];
        this->out << title << ": " << row[title] << endl;
    }
}

/**
 * getDb()
 *
 * method
 *
 * getter
 *
 * returns db
 *
 * @return db
 */
const unordered_map<string, Table> &MenuSystem::getDb() const {
    return db;
}

/**
 * menuOneLoadFromDefaults()
 *
 * method
 *
 * menu item
 *
 * like option 2; but automatically picks the files where all the data is
 *  convenience option to save time testing
 */
void MenuSystem::menuOneLoadFromDefaults() {
    loadTableFromPath("actors", "actor-actress.csv");
    loadTableFromPath("pictures", "pictures.csv");
    loadTableFromPath("nominations", "nominations.csv");
}

/**
 * menuTwoLoad()
 *
 * method
 *
 * menu item
 *
 * prompts user for table/file names then loads tables
 */
void MenuSystem::menuTwoLoad() {
    this->in.ignore();
    string table = this->selectTable();

    this->out << "What is the path of the file?" << endl;
    this->out << "> ";
    string path;
    getline(this->in, path);

    loadTableFromPath(table, path);
}

/**
 * menuThreeAdd()
 *
 * method
 *
 * menu item
 *
 * prompts user for table then fields then inserts a row
 */
void MenuSystem::menuThreeAdd() {
    this->in.ignore();
    string tableName = this->selectTable();
    Table table = db[tableName];
    vector<string> tableTitles = table.getTitles();
    unordered_map<string, string> row;
    for (unsigned int i = 0; i < tableTitles.size(); i++) {
        string title = tableTitles[i];
        this->out << "Please enter a value for \"" << title << "\"" << endl;
        this->out << "> ";

        string value;
        getline(this->in, value);

        row[title] = value;
    }
    table.add(row);
    this->out << "Successfully added entry." << endl;
}

/**
 * menuFourFind()
 *
 * method
 *
 * menu item
 *
 * prompts user for table then fields then finds a row via exact match
 */
void MenuSystem::menuFourFind() {
    this->in.ignore();
    string tableName = this->selectTable();

    this->out << "Which field should be searched by?" << endl;
    this->out << "Valid fields: ";
    Table table = db[tableName];
    vector<string> tableTitles = table.getTitles();
    for (unsigned int i = 0; i < tableTitles.size(); i++) {
        string title = tableTitles[i];
        this->out << title;
        if (i < tableTitles.size() - 1) this->out << ", ";
    }
    this->out << endl;
    this->out << "> ";

    string title;
    getline(this->in, title);

    this->out << "What value are you searching for?" << endl;
    this->out << "> ";

    string value;
    getline(this->in, value);

    try {
        unordered_map<string, string> result = table.findByValue(title, value);

        this->out << "Found the following entry: " << endl;
        this->printRow(tableTitles, result);
    } catch (runtime_error e) {
        this->out << "Sorry, we couldn't find anything matching those criteria." << endl;
    }
}

/**
 * menuFiveModify()
 *
 * method
 *
 * menu item
 *
 * prompts user for table then fields then finds a row via exact match then replaces it
 *  with additional fields prompted from the user
 */
void MenuSystem::menuFiveModify() {
    this->in.ignore();
    string tableName = this->selectTable();

    this->out << "Which field should be searched by?" << endl;
    this->out << "Valid fields: ";
    Table table = db[tableName];
    vector<string> tableTitles = table.getTitles();
    for (unsigned int i = 0; i < tableTitles.size(); i++) {
        string title = tableTitles[i];
        this->out << title;
        if (i < tableTitles.size() - 1) this->out << ", ";
    }
    this->out << endl;
    this->out << "> ";

    string title;
    getline(this->in, title);

    this->out << "What value are you searching for?" << endl;
    this->out << "> ";

    string value;
    getline(this->in, value);

    try {
        unordered_map<string, string> result = table.findByValue(title, value);

        this->out << "Found the following entry: " << endl;
        this->printRow(tableTitles, result);

        unordered_map<string, string> row;
        for (unsigned int i = 0; i < tableTitles.size(); i++) {
            string title = tableTitles[i];
            this->out << "Please enter a value for \"" << title << "\"" << endl;
            this->out << "> ";

            string value;
            getline(this->in, value);

            row[title] = value;
        }

        table.replaceByValue(title, value, row);

        this->out << "Successfully modified entry." << endl;
    } catch (runtime_error e) {
        this->out << "Sorry, we couldn't find anything matching those criteria." << endl;
    }
}

/**
 * menuSixDelete()
 *
 * method
 *
 * menu item
 *
 * prompts user for table then fields then finds a row via exact match then deletes it
 */
void MenuSystem::menuSixDelete() {
    this->in.ignore();
    string tableName = this->selectTable();

    this->out << "Which field should be searched by?" << endl;
    this->out << "Valid fields: ";
    Table table = db[tableName];
    vector<string> tableTitles = table.getTitles();
    for (unsigned int i = 0; i < tableTitles.size(); i++) {
        string title = tableTitles[i];
        this->out << title;
        if (i < tableTitles.size() - 1) this->out << ", ";
    }
    this->out << endl;
    this->out << "> ";

    string title;
    getline(this->in, title);

    this->out << "What value are you searching for?" << endl;
    this->out << "> ";

    string value;
    getline(this->in, value);

    try {
        table.removeByValue(title, value);

        this->out << "Successfully removed entry." << endl;
    } catch (runtime_error e) {
        this->out << "Sorry, we couldn't find anything matching those criteria." << endl;
    }
}

/**
 * menuSevenSort()
 *
 * method
 *
 * menu item
 *
 * prints a sorted version of a table; sorted by field that the user is prompted for
 */
void MenuSystem::menuSevenSort() {
    this->in.ignore();
    string tableName = this->selectTable();

    this->out << "Which field should be searched by?" << endl;
    this->out << "Valid fields: ";
    Table table = db[tableName];
    vector<string> tableTitles = table.getTitles();
    for (unsigned int i = 0; i < tableTitles.size(); i++) {
        string title = tableTitles[i];
        this->out << title;
        if (i < tableTitles.size() - 1) this->out << ", ";
    }
    this->out << endl;
    this->out << "> ";

    string title;
    getline(this->in, title);

    try {
        table.printInOrderBy(title);
    } catch (runtime_error e) {
        this->out << "Sorry, no column by that name was found." << endl;
    }
}

/**
 * menuEightPartialSearch()
 *
 * method
 *
 * menu item
 *
 * prompts user for table/field names then searches database for partial match
 */
void MenuSystem::menuEightPartialSearch() {
    this->in.ignore();
    string tableName = this->selectTable();

    this->out << "Which field should be searched by?" << endl;
    this->out << "Valid fields: ";
    Table table = db[tableName];
    vector<string> tableTitles = table.getTitles();
    for (unsigned int i = 0; i < tableTitles.size(); i++) {
        string title = tableTitles[i];
        this->out << title;
        if (i < tableTitles.size() - 1) this->out << ", ";
    }
    this->out << endl;
    this->out << "> ";

    string title;
    getline(this->in, title);

    this->out << "What value are you searching for?" << endl;
    this->out << "> ";

    string value;
    getline(this->in, value);

    try {
        unordered_map<string, string> result = table.findByPartialValue(title, value);

        this->out << "Found the following entry: " << endl;
        this->printRow(tableTitles, result);
    } catch (runtime_error e) {
        this->out << "Sorry, we couldn't find anything matching those criteria." << endl;
    }
}

/**
 * menuNineWrite()
 *
 * method
 *
 * menu item
 *
 * prompts user for table and path the writes the table to that path
 */
void MenuSystem::menuNineWrite() {
    this->in.ignore();
    string tableName = this->selectTable();
    Table table = db[tableName];

    this->out << "What path should this data be written to?" << endl;
    this->out << "> ";

    string path;
    getline(this->in, path);

    ofstream out;
    out.open(path);

    table.writeTable(out);

    out.close();
}