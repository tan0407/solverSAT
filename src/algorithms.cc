#include "headers/algorithms.h"
#include <iostream>
using namespace std;


/*
	*@desc Vérifie si un littéral contient une clause vide
	*@param vector<vector<int>> cnf - Forme normale conjonctive à tester
	*@return True si la formule contient une clause vide, Faux sinon
*/
bool emptyClause(vector<vector<int>> cnf){
	for(vector<int> clause : cnf){
		if(clause.empty()){
			return true;	
		}
	}
	return false;	
}

/*
	*@desc Simplifie une CNF sur un littéral donné
	*@param vector<vector<int>> cnf - cnf de base
			int literal - littéral utilisé pour simplifier
	*@return CNF simplifiée sur le littéral
*/
vector<vector<int>> simplifyCnf(vector<vector<int> > cnf, int literal) {
	vector<vector<int>> cnf_new = vector<vector<int>>(cnf);
	int not_literal = literal * (-1);
    
	for (int i = 0; i < cnf_new.size(); i++) {
		for (int j = 0; j < cnf_new[i].size(); j++) {

			if (cnf_new[i][j] == not_literal) {
				// on supprime la négation du littéral testé sur cette clause
				cnf_new[i].erase(cnf_new[i].begin() + j);
				break;
			}

			else if (cnf_new[i][j] == literal) {
				// on supprime la clause
				cnf_new.erase(cnf_new.begin() + i);
				i--;
                break;
			}
		}

	}
	return cnf_new;
}


/*
	*@desc Détermine la satisfaisabilité d'une CNF, en fournissant son modèle.
	*@param vector<vector<int>> cnf - La forme normale conjonctive à tester
			vector<int> var - Les littéraux à tester
			vector<int> &model - Interprétation qui satisfait la cnf (déterminée récursivement)
	*@return bool - True si la CNF est satisfaisable, false sinon.
*/
bool backtracking(vector<vector<int>> cnf, vector<int> var, vector<int> &model){

	vector<int> variables = var;
	int v = variables[0];		
	variables.erase(variables.begin());

	vector< vector<int>> simplified = simplifyCnf(cnf, v);

	//Si la cnf simplifiée est vide, on a trouvé un modèle. La cnf est satisfaisable.
	if(simplified.empty()){
		model.push_back(v);
		return true;
	}
	else{
		//Si la cnf simplifiée contient une clause vide, on vérifie la satisfaisabilité sur la négation du littéral v.
		if(emptyClause(simplified)){
			int not_v = v*(-1);
			vector< vector<int>> simplified_second = simplifyCnf(cnf, not_v);
			if(simplified_second.empty()){
				model.push_back(not_v);
				return true;
			}
			else{
				if(emptyClause(simplified_second)){
					return false;
				}
				else{
					model.push_back(not_v);
					return backtracking(simplified_second,variables,model);
				}
			}
		}
		else{
			model.push_back(v); 
			return backtracking(simplified,variables,model);
		}
	}
}