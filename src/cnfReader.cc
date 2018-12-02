#include "headers/fileReader.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*
	*@desc Lit le fichier .cnf et retourne la liste des clauses en initialisant en meme temps la liste des variables
	*@param char * filePath - Le nom du fichier avec son chemin
            vector<int>& var - La liste des variables qui va etre initialisée
	*@return vector<vector<int>> - La liste des clauses dans le fichier
*/
vector<vector<int> > fileToClause(char* filePath,vector<int>& var){
    string fp(filePath);
    //Verify the file extension
    if(fp.substr(fp.find_last_of(".")+1)!="cnf"){
        cout<<"Error : file extension invalid"<<endl;
        exit(-1);
    }
    ifstream file(filePath);
    //Verify if the file can be read
    if (!file){
        cout<<"Error while reading file"<<endl;
        cout<<"Maybe the file doesn't exist"<<endl;
        exit(-1);
    }
    string mot;
    // Reading the first line
    file>> mot; //p
    file>> mot; //cnf
    int nbVariables;
    file>> nbVariables; //nb variables
    int nbClauses;
    file>> nbClauses; //nb clauses

    //Initialization of the variables array
    for (int i=0;i<nbVariables;i++){
        var.push_back(i+1);
    }   

    //reading the clauses in the file
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
