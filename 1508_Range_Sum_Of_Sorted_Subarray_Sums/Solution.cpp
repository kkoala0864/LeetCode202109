#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::pair;
using std::cout;
using std::endl;

int Solution::rangeSum(vector<int>& nums, int n, int left, int right) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	vector<int> idxs;
	for (int i = 0 ; i < n ; ++i) {
		pq.emplace(pair<int, int>(nums[i], i));
		idxs.emplace_back(i);
	}

	int mod = 1e9 + 7;
	int result = 0;

	for (int i = 1 ; i <= right ; ++i) {
		int curV = pq.top().first;
		int curIdx = pq.top().second;
		pq.pop();

		if (i >= left) {
			result += curV;
			result %= mod;
		}

		++curIdx;
		if (curIdx >= nums.size()) continue;
		pq.emplace(pair<int, int>(curV + nums[curIdx], curIdx));
	}
	return result;
}
