//
// Created by Jake Billings on 4/11/18.
//

#ifndef EDU_CSCI2421_TABLE_H
#define EDU_CSCI2421_TABLE_H

/**
 * Table
 *
 * class
 *
 * represents a query-able set of rows or one "table" in the database
 *
 * tables store records in the database and provide access to functions that modify this data
 */
class Table {
public:
    vector<Row> insert(Row row);
    vector<Row> update(Query q, Row row);
    vector<Row> remove(Query q);
    vector<Row> get(Query q);
};


#endif //EDU_CSCI2421_TABLE_H
