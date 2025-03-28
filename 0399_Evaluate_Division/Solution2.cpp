#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

double find(unordered_map<string, unordered_map<string, double>> &uMap, const string &cur, const string &end, unordered_set<string> &visited) {
	if (uMap[cur].find(end) != uMap[cur].end())
		return uMap[cur][end];

	for (const auto &e : uMap[cur]) {
		if (visited.find(e.first) != visited.end())
			continue;
		visited.emplace(e.first);
		double local = find(uMap, e.first, end, visited);
		if (local != -1) {
			uMap[cur][end] = e.second * local;
			return uMap[cur][end];
		}
	}
	return -1;
}

vector<double> Solution::calcEquation2(vector<vector<string>> &equations,
                                       vector<double> &values, vector<vector<string>> &queries) {

	unordered_map<string, unordered_map<string, double>> uMap;

	for (int i = 0; i < equations.size(); ++i) {
		uMap[equations[i][0]][equations[i][1]] = values[i];
		uMap[equations[i][1]][equations[i][0]] = values[i] == 0 ? 0 : 1 / values[i];
	}

	vector<double> result;
	for (const auto &q : queries) {
		if (uMap.find(q[0]) == uMap.end() || uMap.find(q[1]) == uMap.end())
			result.emplace_back(-1);
		else {
			if (q[0] == q[1])
				result.emplace_back(1);
			else {
				unordered_set<string> visited;
				double local = find(uMap, q[0], q[1], visited);
				result.emplace_back(local);
			}
		}
	}
	return result;
}
