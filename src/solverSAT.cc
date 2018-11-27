#include <iostream>
#include "headers/fileReader.h"
using namespace std;

int main(int argc, char **argv) {
	 char* file = argv[1];
	    vector<vector<int> > clausesInFile = fileToClause(file);
	    return 0;
}
