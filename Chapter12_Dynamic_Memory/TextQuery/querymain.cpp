#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>
using std::cout; using std::endl; using std::cin; using std::ifstream;

void runQuery(ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char** argv) {
    ifstream infile;

    if (argc < 2 || !(infile.open(argv[1]), infile)) {
        std::cerr << "No input file!" << std::endl;
        return EXIT_FAILURE;
    }
    runQuery(infile);
    return 0;
}
