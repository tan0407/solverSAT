#include "./headers/fileReader.h"
#include <iostream>
#include <string>

vector<Litteral> fileToClause(string filePath){
    ifstream file;
    file.open(filePath);
    if (!file){
        cout<<"Error while reading file"<<endl;
        return EXIT_FAILURE;
    }
    string line;
    while (getline(infile, line)){
    istringstream iss(line);
    
    }
}
