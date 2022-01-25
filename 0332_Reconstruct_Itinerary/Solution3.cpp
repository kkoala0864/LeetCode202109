#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>

using std::unordered_map;
using std::set;
using std::priority_queue;

void traverse(unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>>& uMap, const string& place, vector<string>& result) {
	while (!uMap[place].empty()) {
		string next = uMap[place].top();
		uMap[place].pop();
		traverse(uMap, next, result);
	}
	result.emplace_back(place);
}

vector<string> Solution::findItinerary3(vector<vector<string>>& tickets) {
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> uMap;

	for (const auto& ticket : tickets) uMap[ticket[0]].emplace(ticket[1]);

	vector<string> result;
	traverse(uMap, "JFK", result);
	reverse(result.begin(), result.end());
	return result;
}
