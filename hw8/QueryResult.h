//
// Created by Jake Billings on 4/11/18.
//

#ifndef EDU_CSCI2421_QUERYRESULT_H
#define EDU_CSCI2421_QUERYRESULT_H

/**
 * QueryResult
 *
 * class
 *
 * represents the result of a query
 *  contains a list of "affected" rows and a duration
 */
class QueryResult {
private:
    vector<Row> rows;
    unsigned long duration;
public:
    Row getNextRow();
    unsigned long getRowCount();
    unsigned long getDuration();
};


#endif //EDU_CSCI2421_QUERYRESULT_H
