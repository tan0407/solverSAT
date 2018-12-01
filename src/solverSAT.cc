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
	
	string arg(file);
	vector<int> variables{};
	vector<int> model{};
	vector<vector<int> > clauses = fileToClause(file,variables);
	
	bool sat = backtracking(clauses,variables,model);
	if(sat){
		cout << "SATISFIABLE" << endl;
		cout<< "Model :";
		for (int i : model)
			cout<<" "<<i<<" ";
		cout<<endl;
	}
	else{
		cout << "UNSAT"<<endl;
	}
	
	return 0;
}
