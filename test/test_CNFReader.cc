#include "../src/headers/fileReader.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string file = argv[1];
    vector<Clause> clausesInFile = fileToClause(file);
    for (int i=0;i<clausesInFile.size();i++){
        vector<int> litteral = clausesInFile[i].getClause();
        for (int j=0;j<litteral.size();j++){
            cout<< "Clause "<<i<<" , litteral "<<j<< " = "<<litteral[j]<<endl;
        }
    }
    return 0;
}
