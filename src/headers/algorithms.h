#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_
#include <vector>
using std::vector;
vector<vector<int>> simplifyCnf(vector<vector<int> > cnf, int literal);
bool backtracking(vector<vector<int>> cnf, vector<int> var, vector<int> &model);

#endif
