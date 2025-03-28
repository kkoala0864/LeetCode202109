#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::to_string;

struct cmp
{
	bool operator()(const string &lhs, const string &rhs) {
		string lF = lhs + rhs;
		string rF = rhs + lhs;
		for (int i = 0; i < lF.size(); ++i) {
			if (lF[i] == rF[i])
				continue;
			return lF[i] < rF[i];
		}
		return false;
	}
};

string Solution::largestNumber(vector<int> &nums) {
	vector<priority_queue<string, vector<string>, cmp>> map(10, priority_queue<string, vector<string>, cmp>());
	for (int i = 0; i < nums.size(); ++i) {
		string ele = to_string(nums[i]);
		map[ele[0] - '0'].emplace(ele);
	}

	string result("");
	for (int i = map.size() - 1; i >= 0; --i) {
		while (!map[i].empty()) {
			result += map[i].top();
			map[i].pop();
		}
	}

	return result[0] == '0' ? "0" : result;
}
