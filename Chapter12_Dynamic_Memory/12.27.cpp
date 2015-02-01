#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
using std::cout; using std::endl;

int main() {
    TextQuery text_query("a.txt");
    //text_query.print_content();
    //text_query.print_map();
    QueryResult result = text_query.query("five");
    //print(cout, result);
    return 0;
}
