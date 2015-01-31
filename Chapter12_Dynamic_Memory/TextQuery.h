#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "QueryResult.h"
using std::string; using std::vector; using std::set; using std::map;
using std::cout; using std::endl;

class TextQuery {
public:
    friend class QueryResult;
    TextQuery(){}
    TextQuery(string file);
    QueryResult query(string s);
    void print_content() {
        for (auto line : content)
            cout << line << endl;
    }
    void print_map() {
        cout << word_lines.size() << endl;
        for (auto i : word_lines) {
            cout << i.first << " occurs " << endl;
           //for (auto iter = i.second.begin(); iter != i.second.end(); ++iter)
           //    cout << "   line " << *iter << " " << content[*iter - 1] << endl;
           for (auto no : i.second) {
               cout << "   line " << no << " " << content[no - 1] << endl;
           }
        }
    }

private:
    vector<string> content;
    map<string, set<int>> word_lines;
};

#endif
