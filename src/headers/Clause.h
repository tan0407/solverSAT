#include "Litteral.h"
#include <vector>
using std::vector;

class Clause {
private:
    vector<Litteral> clause;
public: 
    Clause();
    void addLitteral(Litteral litteral);
    vector<Litteral> getClause();
};