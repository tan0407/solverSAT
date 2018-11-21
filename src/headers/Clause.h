#include "Litteral.h"
#include <vector>
using std::vector;

class Clause {
private:
    vector<Litteral> clause;
public: 
    Clause();
    Clause(vector<Litteral> litteraux);
    void addLitteral(Litteral litteral);

}