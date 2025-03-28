#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

double find(unordered_map<string, unordered_map<string, double>> &relation,
            unordered_map<string, bool> &visited,
            double val, string end, string cur) {
	if (cur == end)
		return val;
	visited[cur] = true;
	for (const auto &iter : relation[cur]) {
		if (visited[iter.first])
			continue;
		double result = find(relation, visited, val * iter.second, end, iter.first);
		if (result > 0)
			return result;
	}
	return -1;
}

vector<double> Solution::calcEquation(vector<vector<string>> &equations,
                                      vector<double> &values, vector<vector<string>> &queries) {
	unordered_map<string, unordered_map<string, double>> relation;

	for (int i = 0; i < equations.size(); ++i) {
		relation[equations[i][0]][equations[i][1]] = values[i];
		relation[equations[i][1]][equations[i][0]] = 1 / values[i];
	}

	vector<double> result;
	for (const auto &iter : queries) {
		if (relation.find(iter[0]) == relation.end() || relation.find(iter[1]) == relation.end()) {
			result.emplace_back(-1);
			continue;
		}
		unordered_map<string, bool> visited;
		double val = find(relation, visited, 1, iter[1], iter[0]);
		result.emplace_back(val);
	}
	return result;
}
