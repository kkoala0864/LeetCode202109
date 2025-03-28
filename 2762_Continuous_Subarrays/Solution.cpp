#include <Solution.h>
#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

long long Solution::continuousSubarrays(vector<int> &nums) {
	long long result = 0;

	int l = 0;
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		++m[nums[i]];

		while (abs(m.begin()->first - m.rbegin()->first) > 2) {
			--m[nums[l]];
			if (m[nums[l]] == 0)
				m.erase(nums[l]);
			++l;
		}
		result += (i - l + 1);
	}
	return result;
}
