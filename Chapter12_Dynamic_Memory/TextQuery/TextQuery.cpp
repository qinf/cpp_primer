#include "TextQuery.h"
#include <sstream>
using std::istringstream;

TextQuery::TextQuery(ifstream &in): file(new vector<string>) {
    string line, word;
    while(getline(in, line)) {
        file->push_back(line);
        int n = file->size() - 1;
        istringstream ins(line);
        while(ins >> word) {
            auto &lines = word_map[word];
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &word) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto pos = word_map.find(word);
    if (pos == word_map.end())
        return QueryResult(word, nodata, file);
    else
        return QueryResult(word, pos->second, file);
}
