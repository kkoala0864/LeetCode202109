#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
// atMost(k) -  atMost(k-1) = exact(k);

int atMost(vector<int>& nums, int k) {
	int l = 0;
	unordered_map<int, int> m;
	int result = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		++m[nums[i]];
		while (m.size() > k) {
			--m[nums[l]];
			if (m[nums[l]] == 0) m.erase(nums[l]);
			++l;
		}
		result += (i - l + 1); // count of [i~l, l]
				       // 0 1 2 3
				       // end with 0
				       // [0]
				       // end with 1
				       // [1], [0,1]
				       // end with 2
				       // [2], [1,2], [0,1,2]
				       // end with 3
				       // [3], [2,3], [1,2,3], [0,1,2,3]
	}
	return result;
}

int Solution::subarraysWithKDistinct(vector<int>& nums, int k) {
	return atMost(nums, k) - atMost(nums, k-1);
}
