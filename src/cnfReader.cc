#include "headers/fileReader.h"
#include <iostream>
#include <string>
#include <math.h>

vector<Clause> fileToClause(string filePath){
    ifstream file(filePath);
    
    if (!file){
        cout<<"Error while reading file"<<endl;
        return EXIT_FAILURE;
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
        clauses[actualClause].addLitteral(Litteral(abs(variable),variable<0?true:false));          
    }

    file.close();
    return clauses;
}
