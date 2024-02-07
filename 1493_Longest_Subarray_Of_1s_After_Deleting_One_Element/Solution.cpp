#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::max;

int Solution::longestSubarray(vector<int>& nums) {
	pair<int, int> last, cur;

	int result = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		cur.first = nums[i] == 0 ? 0 : last.first + 1;
		cur.second = nums[i] == 0 ? last.first : last.second + 1;
		result = max({result, cur.first, cur.second});
		swap(cur, last);
	}
	if (last.first == nums.size()) return last.first - 1;
	return result;
}

