#include "headers/algorithms.h"
#include <iostream>
using namespace std;
vector<vector<int>> simplifyCnf(vector<vector<int> > cnf, int literal) {
	vector<vector<int>> cnf_new = vector<vector<int>>(cnf);
	int not_literal = literal * (-1);
    
	for (int i = 0; i < cnf_new.size(); i++) {
		for (int j = 0; j < cnf_new[i].size(); j++) {
			if (cnf_new[i][j] == not_literal) {
				cnf_new[i].erase(cnf_new[i].begin() + j);
				break;
			}
			else if (cnf_new[i][j] == literal) {
				cnf_new.erase(cnf_new.begin() + i);
				i--;
                break;
			}
		}

	}
	return cnf_new;
}

bool backtracking(vector<vector<int>> cnf, vector<int> var, vector<int> &model){

	vector<int> variables = var;
	int v = variables.back();
	variables.pop_back();

	vector< vector<int>> simplified = simplifyCnf(cnf, v);

	if(simplified.empty()){
		model.push_back(v);
		return true;
	}
	else{
		if(simplified.size()<cnf.size()){
			int not_v = v*(-1);
			vector< vector<int>> simplified_second = simplifyCnf(cnf, not_v);
			if(simplified_second.empty()){
				model.push_back(not_v);
				return true;
			}
			else{
				if(simplified_second.size()<simplified.size()){
					return false;
				}
				else{
					return backtracking(simplified_second,variables,model);
				}
			}
		}
		else{
			return backtracking(simplified,variables,model);
		}


	}



}
