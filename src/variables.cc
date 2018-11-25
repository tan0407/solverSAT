#include "headers/Clause.h"
#include <vector>
Clause::Clause(){
    clause = vector<Litteral>();
}
void Clause::addLitteral(Litteral litteral){
    clause.push_back(litteral);
}
vector<Litteral> getClause(){
    return this->clause;
}