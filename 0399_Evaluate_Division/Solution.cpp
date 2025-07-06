#include <Solution.h>

double dfs(const string& cur, const string& target, unordered_set<string>& visited,
		unordered_map<string, unordered_map<string, double>>& value) {
	if (value.count(cur) && value[cur].count(target)) return value[cur][target];

	if (visited.count(cur)) return -1;
	visited.emplace(cur);

	if (cur == target) return 1;

	for (const auto& e : value[cur]) {
		double v = dfs(e.first, target, visited, value);

		if (v != -1) {
			return value[cur][target] = e.second * v;
		}
	}
	return -1;
}

vector<double> Solution::calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
	unordered_map<string, unordered_map<string, double>> value;

	for (int i = 0 ; i < equations.size() ; ++i) {
		value[equations[i][0]][equations[i][1]] = values[i];
		value[equations[i][1]][equations[i][0]] = 1/values[i];
	}
	vector<double> result;
	for (const auto& q : queries) {
		if (value.count(q[0]) == 0 || value.count(q[1]) == 0) result.emplace_back(-1);
		else if (q[0] == q[1]) {
			result.emplace_back(1);
		} else {
			unordered_set<string> visited;
			result.emplace_back(dfs(q[0], q[1], visited, value));
		}
	}
	return result;
}
