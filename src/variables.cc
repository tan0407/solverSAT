#include "headers/Clause.h"
#include <vector>

Clause::Clause(){
    clause = vector<Litteral>();
}
void Clause::addLitteral(Litteral litteral){
    clause.push_back(litteral);
}
vector<Litteral> Clause::getClause(){
    return this->clause;
}

int Litteral::getNumber(){
    return this->number;
}