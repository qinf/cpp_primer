#include "TextQuery.h"
#include <fstream>
#include <sstream>
using std::ifstream; using std::istringstream;

TextQuery::TextQuery(string file) {
    ifstream in(file);
    string line, word;
    int count = 0;
    while(getline(in, line)) {
        content.push_back(line);
        istringstream ins(line);
        ++count;
        while(ins >> word) {
            if(word_lines.find(word) != word_lines.end()) {
                word_lines[word].insert(count);
            }
        }
    }
}

QueryResult TextQuery::query(string s) {
    QueryResult result(word_lines.find(s), content);
    return result;
}
