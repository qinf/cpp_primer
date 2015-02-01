#include "QueryResult.h"
ostream &print(ostream &os, const QueryResult &result) {
    os << result.word << " occurs " << result.lines->size() << "time" << (result.lines->size() > 1 ? "s" : "") << std::endl;
    for (auto num : *result.lines)
        os << "\t(line " << num + 1 << ") "
           << *(result.file->begin() + num) << std::endl;
    return os;
}
