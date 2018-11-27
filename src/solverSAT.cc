#include <iostream>
#include "headers/fileReader.h"
using namespace std;

int main(int argc, char **argv) {
	if (argc!=1){
		cout<<"Argument error : specify one argument"<<endl;
		exit(-1);
	}
	char* file = argv[1];
	vector<vector<int> > clausesInFile = fileToClause(file);

	//prints the variables
/*	for (int i=0;i<clausesInFile.size();i++){
   		vector<int> litteral = clausesInFile[i];
	   	for (int j=0;j<litteral.size();j++){
           	cout<< "Clause "<<i+1<<" , litteral "<<j+1<< " = "<<litteral[j]<<endl;
       	}
    }
*/
	return 0;
}
