#include <ifstream>
#include <string>
#include "Clause.h"

using namespace std;

ifstream readCNFFile(string filePath);
Clause fileToClause(ifstream stream);
