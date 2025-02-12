#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::unordered_map;
using std::priority_queue;
using std::max;

int Solution::maximumSum(vector<int>& nums) {
	unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> sum;
	for (const auto& v : nums) {
		int curSum = 0;
		int tmp = v;
		while (tmp > 0) {
			curSum += (tmp % 10);
			tmp /= 10;
		}
		sum[curSum].emplace(v);
		while (sum[curSum].size() > 2) sum[curSum].pop();
	}
	int result = -1;
	for (auto& e : sum) {
		if (e.second.size() < 2) continue;
		int cur = 0;
		while (!e.second.empty()) {
			cur += e.second.top();
			e.second.pop();
		}
		result = max(result, cur);
	}
	return result;
}
