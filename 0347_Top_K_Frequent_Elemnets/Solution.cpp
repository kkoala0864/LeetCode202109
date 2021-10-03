#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::priority_queue;
using std::unordered_map;
using std::pair;

struct cmp {
	bool operator() (const pair<int,int>& lhs, const pair<int, int>& rhs) {
		return lhs.second < rhs.second;
	}
};

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> heap;
	unordered_map<int, int> cnt;
	vector<int> result;
	for (const auto& iter : nums) ++cnt[iter];
	for (const auto& iter : cnt) heap.emplace(iter);
	for (int i = 0 ; i < k ; ++i) {
		result.emplace_back(heap.top().first);
		heap.pop();
	}
	return result;
}
