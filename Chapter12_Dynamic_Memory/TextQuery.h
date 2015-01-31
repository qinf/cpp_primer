#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include "QueryResult.h"
using std::string; using std::vector; using std::set; using std::map;

class TextQuery {
public:
    friend class QueryResult;
    TextQuery(){}
    TextQuery(string file);
    QueryResult query(string s);

private:
    vector<string> content;
    map<string, set<int>> word_lines;
};

#endif
