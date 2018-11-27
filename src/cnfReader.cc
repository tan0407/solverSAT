#include "headers/fileReader.h"
//#include "headers/Clause.h"
//#include "headers/Litteral.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

vector<Clause> fileToClause(string filePath){
    ifstream file(filePath);
   // file.open(filePath);
    if (!file){
        cout<<"Error while reading file"<<endl;
        exit(-1);
    }
    string mot;
    file>> mot; //p
    file>> mot; //cnf
    int nbVariables;
    file>> nbVariables; //nb variables
    int nbClauses;
    file>> nbClauses; //nb clauses
    
    vector<Clause> clauses (nbClauses,Clause());
    int actualClause=0;
    int variable;
    while(actualClause<nbClauses){
        file>>variable;
        if(variable==0){
            actualClause++;
            continue;
        }
        clauses[actualClause].addLitteral(abs(variable));          
    }

    file.close();
    return clauses;
}
