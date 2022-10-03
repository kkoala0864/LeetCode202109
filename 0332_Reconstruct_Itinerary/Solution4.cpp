#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::unordered_map;
using std::priority_queue;
using std::reverse;

void traversal(unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>>& toLoc, string& curLoc, vector<string>& result) {
	while (!toLoc[curLoc].empty()) {
		string nextLoc = toLoc[curLoc].top();
		toLoc[curLoc].pop();
		traversal(toLoc, nextLoc, result);
	}
	result.emplace_back(curLoc);
}

vector<string> Solution::findItinerary4(vector<vector<string>>& tickets) {
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> toLoc;
	for (const auto& t : tickets) toLoc[t[0]].emplace(t[1]);

	vector<string> result;
	string startLoc = "JFK";
	traversal(toLoc, startLoc, result);
	reverse(result.begin(), result.end());
	return result;
}
