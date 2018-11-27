#include "headers/fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

vector<vector<int> > fileToClause(char* filePath){
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

    vector<vector<int> > clauses (nbClauses);
    int actualClause=0;
    int variable;
    while(actualClause<nbClauses){
        file>>variable;
        if(variable==0){
            actualClause++;
            continue;
        }
        clauses[actualClause].push_back(variable);
    }

    file.close();
    return clauses;
}
