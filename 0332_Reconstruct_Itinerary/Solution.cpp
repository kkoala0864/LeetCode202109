#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// Fleury's Algorithm : Find Eulerian Cycle of Graph
void traverse(const string &cur, unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &uMap, vector<string> &result) {
	while (!uMap[cur].empty()) {
		string next = uMap[cur].top();
		uMap[cur].pop();
		traverse(next, uMap, result);
	}
	result.emplace_back(cur);
}

vector<string> Solution::findItinerary(vector<vector<string>> &tickets) {
	vector<string> result;
	if (tickets.empty())
		return result;
	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> uMap;
	for (const auto &iter : tickets)
		uMap[iter[0]].emplace(iter[1]);

	traverse("JFK", uMap, result);
	reverse(result.begin(), result.end());
	return result;
}
