#include <Solution.h>

vector<int> Solution::maxKDistinct(vector<int>& nums, int k) {
	set<int, greater<>> s;

	for (const auto& v : nums) s.emplace(v);

	vector<int> result;
	auto iter = s.begin();
	while (k-- > 0 && iter != s.end()) {
		result.emplace_back(*iter++);
	}
	return result;

}
