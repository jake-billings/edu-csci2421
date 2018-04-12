//
// Created by Jake Billings on 4/11/18.
//

#ifndef EDU_CSCI2421_QUERY_H
#define EDU_CSCI2421_QUERY_H

/**
 * Query
 *
 * abstract class
 *
 * Query objects identify subsets of a table via the function isRowIncluded()
 *  subclasses of query can include exact field matches and searchs
 */
class Query {
public:
    virtual bool isRowIncluded(Row row);
};


#endif //EDU_CSCI2421_QUERY_H
