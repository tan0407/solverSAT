#include <iostream>
#include "headers/fileReader.h"
#include "headers/algorithms.h"
using namespace std;

int main(int argc, char **argv) {
	if (argc!=2){
		cout<<"Argument error : specify one argument"<<endl;
		exit(-1);
	}
	char* file = argv[1];
	vector<int> variables{};
	vector<int> model{};
	vector<vector<int> > clauses = fileToClause(file,variables);

	//prints the variables
/*	for (int i=0;i<clauses.size();i++){
   		vector<int> litteral = clauses[i];
	   	for (int j=0;j<litteral.size();j++){
           	cout<< "Clauses "<<i+1<<" , litteral "<<j+1<< " = "<<litteral[j]<<endl;
       	}
    }
*/
	bool sat = backtracking(clauses,variables,model);
	if(sat){
		cout << "SATISFIABLE" << endl;
		cout<< "Model :";
		for (int i : model)
			cout<<" "<<i<<" ";
		cout<<endl;
	}
	else{
		cout << "UNSAT";
	}
	
	return 0;
}
