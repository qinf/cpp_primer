#include "QueryResult.h"

void print(ostream &os, QueryResult &result) {
    //if (result.result_iter->second.empty()) {
    //    os << result.result_iter->first << "does not occurs" << endl;
    //    return;
    //}
    os << result.result_iter->first << " occurs " << result.result_iter->second.size() << " time" << (result.result_iter->second.size() > 1 ? "s" : "") << endl;
    for (auto i : result.result_iter->second) {
        os << " (line " <<  i << ") " << result.svec[i - 1] << endl;
    }
}
