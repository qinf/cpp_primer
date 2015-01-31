#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <string>
#include <map>
#include <iostream>
using std::string; using std::map; using std::ostream;

class QueryResult {
public:
    QueryResult(){}
    QueryResult(map<string, set<int>>::iterator iter): result_iter(iter) {}
    void print(ostream &os, map<string, set<int>>::itreator &result);
private:
    map<string, set<int>>::iterator result_iter;
};
#endif
