#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

void traverse(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& uMap, string cur, vector<string>& result) {
	while (!uMap[cur].empty()) {
		string next = uMap[cur].top();
		uMap[cur].pop();
		traverse(uMap, next, result);
	}
	result.emplace_back(cur);
}

vector<string> Solution::findItinerary2(vector<vector<string>>& tickets) {
	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> uMap;
	for (const auto& ticket : tickets) {
		uMap[ticket[0]].emplace(ticket[1]);
	}

	vector<string> result;
	traverse(uMap, "JFK", result);
	reverse(result.begin(), result.end());

	return result;
}
