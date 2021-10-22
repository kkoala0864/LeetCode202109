#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using std::unordered_map;
using std::priority_queue;
using std::vector;

struct cmp {
	bool operator() (const vector<int>&lhs, const vector<int>& rhs) {
		return lhs[0] < rhs[0];
	}
};

string Solution::frequencySort(string s) {
	unordered_map<int, int> uCnt;
	for (const auto& iter : s) ++uCnt[iter-'0'];

	priority_queue<vector<int>, vector<vector<int>>, cmp> maxHeap;

	for (const auto& iter : uCnt) {
		vector<int> tmp = {iter.second, iter.first};
		maxHeap.emplace(tmp);
	}
	string result("");
	while (!maxHeap.empty()) {
		string append(maxHeap.top()[0], maxHeap.top()[1] + '0');
		result += append;
		maxHeap.pop();
	}
	return result;
}
