#include <iostream>
#include <cmath>
#include <algorithm>    // std::reverse
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
		cout << "s SATISFIABLE" << endl;
		cout << "v ";
		int x = abs(model.back());
		for(int i = 1;i<x;i++)
			cout<<i<<" ";
		for (int i = model.size()-1 ; i>= 0 ; i--)
			cout<<model[i]<<" ";
		for(int i = model[0]+1;i<=variables.size();i++)
			cout <<i<<" "; 
		cout<<endl;
	}
	else{
		cout << "s UNSATISFIABLE"<<endl;

	}
	
	return 0;
}
