#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <string>
#include <set>
#include <memory>
#include <ostream>
#include <vector>
using std::string; using std::set; using std::shared_ptr;
using std::ostream; using std::vector;

class QueryResult{
public:
    friend ostream &print(ostream &os, const QueryResult &result);
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<set<line_no>> _lines, shared_ptr<vector<string>> _file):
        word(s), lines(_lines), file(_file) { }

private:
    string word;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file; // input file
};

ostream &print(ostream &os, const QueryResult &result);

#endif
