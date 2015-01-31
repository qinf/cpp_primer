#include "QueryResult.h"

void QueryResult::print(ostream &os, map<string, set<int>>::iterator result_iter) {
    os << result_iter->first << " occurs " << result_iter->second.size() << "time" << (result_iter->second.size() > 1 ? "s" : "") << endl;
    for (auto i : result_iter->second) {
        os << "(line " <<  i << " ) " << svec[i] << endl;
    }
}
