#include "../src/headers/fileReader.h"
#include <iostream>
#include <string>
#include <math.h>


int main(int argc, char const *argv[])
{
    string file = argv[1];
    vector<Clause> clausesInFile = fileToClause(file);
    for (int i=0;i<clausesInFile.size();i++){
        vector<Litteral> litteral = clausesInFile[i].getClause();
        for (int j=0;j<litteral.size();j++){
            cout<< "Clause "<<i<<" , litteral "<<j<< " = "<<litteral[j].getNumber()<<endl;
        }
    }
    return 0;
}
