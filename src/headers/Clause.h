#ifndef CLAUSE_H_
#define CLAUSE_H_

#include <vector>
using namespace std;

class Clause {
private:
    vector<int> clause;
public:
    Clause();
    void addLitteral(int litteral);
    vector<int> getClause();
};



#endif /* CLAUSE_H_ */
