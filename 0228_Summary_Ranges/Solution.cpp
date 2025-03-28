#include <Solution.h>
#include <iostream>

using std::to_string;

vector<string> Solution::summaryRanges(vector<int> &nums) {
	vector<string> result;
	int i = 0;
	while (i < nums.size()) {
		int start = i;
		string local = to_string(nums[start]);
		while ((i < nums.size() - 1) && ((nums[i] + 1) == nums[i + 1]))
			++i;
		if (start != i) {
			local += ("->" + to_string(nums[i]));
		}
		result.emplace_back(local);
		++i;
	}
	return result;
}
