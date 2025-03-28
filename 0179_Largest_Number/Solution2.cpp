#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::to_string;

string Solution::largestNumber2(vector<int> &nums) {
	vector<string> list;
	for (const auto &v : nums) {
		list.emplace_back(to_string(v));
	}

	auto cmp = [](const string &lhs, const string &rhs) {
		return (lhs + rhs) > (rhs + lhs);
	};
	sort(list.begin(), list.end(), cmp);
	string result;
	for (const auto &v : list)
		result += v;

	return result[0] == '0' ? "0" : result;
}
