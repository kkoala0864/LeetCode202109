#include <Solution.h>
#include <iostream>
#include <queue>

using std::priority_queue;
using std::to_string;

struct cmp {
	bool operator() (string& lhs, string& rhs) {
		return (lhs + rhs) < (rhs + lhs);
	}
};

string Solution::largestNumber2(vector<int>& nums) {
	priority_queue<string, vector<string>, cmp> heap;
	for (const auto& iter : nums) {
		heap.emplace(to_string(iter));
	}

	string result;
	bool zCheck = false;
	while (!heap.empty()) {
		if (zCheck) {
			result += heap.top();
		} else {
			if (stoi(heap.top()) > 0) {
				zCheck = true;
				result += heap.top();
			}
		}
		heap.pop();
	}

	return zCheck ? result : "0";
}
