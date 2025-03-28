#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::priority_queue;
using std::unordered_map;

struct cmp
{
	bool operator()(const vector<int> &lhs, const vector<int> &rhs) {
		return lhs[1] < rhs[1];
	}
};

vector<int> Solution::topKFrequent2(vector<int> &nums, int k) {
	unordered_map<int, int> freq;
	for (const auto &num : nums)
		++freq[num];

	priority_queue<vector<int>, vector<vector<int>>, cmp> maxHeap;
	for (const auto &iter : freq)
		maxHeap.push({iter.first, iter.second});

	vector<int> result;
	for (int i = 0; i < k; ++i) {
		result.emplace_back(maxHeap.top()[0]);
		maxHeap.pop();
	}
	return result;
}
