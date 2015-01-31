#include "QueryResult.h"

void QueryResult::print(ostream &os, map<string, set<int>::itreator &result_iter) {
    os << result_iter->first << " occurs " << result_iter->second.size() << "time" + (i.second.size() > 1 ? "s" : "") << endl;
    for (auto i : result_iter.second) {
        os << "(line " + i " ) " + content[i] << endl;
    }
}
