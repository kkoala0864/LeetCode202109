#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::priority_queue;
using std::unordered_map;

int find(vector<int> &idx, int x) {
	if (x == idx[x])
		return x;
	return idx[x] = find(idx, idx[x]);
}

string Solution::smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
	vector<int> idx(s.size(), 0);
	unordered_map<int, priority_queue<char, vector<char>, std::greater<char>>> uMap;
	for (int i = 0; i < s.size(); ++i)
		idx[i] = i;

	for (const auto &iter : pairs) {
		int first = find(idx, iter[0]);
		int second = find(idx, iter[1]);
		if (first != second)
			idx[first] = second;
	}

	for (int i = 0; i < s.size(); ++i) {
		int tmp = find(idx, i);
		uMap[tmp].emplace(s[i]);
	}

	string result;
	for (int i = 0; i < s.size(); ++i) {
		int groupIdx = idx[i];
		result.push_back(uMap[groupIdx].top());
		uMap[groupIdx].pop();
	}
	return result;
}
