#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;

string Solution::kthLargestNumber2(vector<string> &nums, int k) {
	auto cmp = [](const string &lhs, const string &rhs) {
		return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
	};

	priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

	for (const auto &v : nums)
		pq.emplace(v);

	string result;
	while (k--) {
		result = pq.top();
		pq.pop();
	}
	return result;
}
