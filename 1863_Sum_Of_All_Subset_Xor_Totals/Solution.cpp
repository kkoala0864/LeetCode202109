#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::subsetXORSum(vector<int>& nums) {
	unordered_map<int, int> m;
	int result = 0;
	m[0] = 1;
	for (const auto& v : nums) {
		auto next = m;
		for (const auto& e : m) {
			int tmp = e.first ^ v;
			next[tmp] += e.second;
			result += (tmp * e.second);
		}
		m = next;
	}
	return result;
}
