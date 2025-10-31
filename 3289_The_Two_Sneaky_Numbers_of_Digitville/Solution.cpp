#include <Solution.h>

vector<int> Solution::getSneakyNumbers(vector<int>& nums) {
	unordered_set<int> us;
	vector<int> result;
	for (const auto& v : nums) {
		if (us.count(v)) result.emplace_back(v);
		else us.emplace(v);
	}
	return result;
}
