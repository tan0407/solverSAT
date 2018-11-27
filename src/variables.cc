#include "headers/Clause.h"
#include <vector>

Clause::Clause(){
    clause = vector<int>();
}
void Clause::addLitteral(int litteral){
    clause.push_back(litteral);
}
vector<int> Clause::getClause(){
    return this->clause;
}