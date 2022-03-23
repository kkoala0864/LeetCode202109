#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using std::unordered_map;
using std::priority_queue;
using std::vector;

struct cmp {
	bool operator() (const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[0] < rhs[0];
	}
};

string Solution::frequencySort2(string s) {
	unordered_map<char, int> uMap;
	for (const auto& c : s) ++uMap[c];

	priority_queue<vector<int>, vector<vector<int>>, cmp> maxheap;
	for (const auto& iter : uMap) {
		maxheap.push({iter.second, iter.first});
	}

	string result;
	while (!maxheap.empty()) {
		auto top = maxheap.top();
		maxheap.pop();
		result += string(top[0], top[1]);
	}
	return result;
}
