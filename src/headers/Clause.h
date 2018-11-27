#ifndef CLAUSE_H

//#include "Litteral.h"
#include <vector>
using std::vector;

class Clause {
private:
    vector<int> clause;
public: 
    Clause();
    void addLitteral(int litteral);
    vector<int> getClause();
};

#endif