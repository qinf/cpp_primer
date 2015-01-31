#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <vector>
using std::string; using std::map; using std::ostream; using std::vector;
using std::set; using std::endl;

class QueryResult {
public:
    //QueryResult(){}
    QueryResult(map<string, set<int>>::iterator iter, vector<string> &vec): result_iter(iter), svec(vec) {}
    void print(ostream &os, map<string, set<int>>::iterator result);
private:
    map<string, set<int>>::iterator result_iter;
    vector<string> &svec;
};
#endif
