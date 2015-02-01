#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <fstream>
#include "QueryResult.h"
using std::string; using std::vector; using std::set; using std::shared_ptr;
using std::map; using std::ifstream;

class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &in);
    QueryResult query(const string &word) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> word_map;
};
#endif
