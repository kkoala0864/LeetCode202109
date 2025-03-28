#include <Solution.h>
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::priority_queue;

struct cmp
{
	bool operator()(const string &lhs, const string &rhs) {
		for (int i = 0; i < lhs.length(); ++i) {
			if (lhs[i] != rhs[i])
				return lhs[i] < rhs[i];
		}
		return true;
	}
};

string Solution::kthLargestNumber(vector<string> &nums, int k) {
	vector<priority_queue<string, vector<string>, cmp>> map(101, priority_queue<string, vector<string>, cmp>());
	for (const auto &iter : nums) {
		map[(int)iter.size()].emplace(iter);
	}

	int cnt = 0;
	string cur("");
	for (int i = 100; i >= 0; --i) {
		cnt += map[i].size();
		if (cnt >= k) {
			cnt -= map[i].size();
			while (!map[i].empty()) {
				cur = map[i].top();
				map[i].pop();
				++cnt;
				if (cnt == k)
					return cur;
			}
		}
	}
	return "";
}
