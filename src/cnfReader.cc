#include "headers/fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

vector<vector<int> > fileToClause(char* filePath,vector<int>& var){
    string fp(filePath);
    if(fp.substr(fp.find_last_of(".")+1)!="cnf"){
        cout<<"Error : file extension invalid"<<endl;
        exit(-1);
    }
    ifstream file(filePath);

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
    for (int i=0;i<nbVariables;i++){
        var.push_back(i+1);
    }   
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
