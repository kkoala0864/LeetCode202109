#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::subsets3(vector<int>& nums) {
	vector<vector<int>> result;
	result.push_back({});
	for (const auto& v : nums) {
		auto tmp = result;
		for (auto& e : result) {
			e.emplace_back(v);
			tmp.emplace_back(e);
		}
		result = tmp;
	}
	return result;
}
