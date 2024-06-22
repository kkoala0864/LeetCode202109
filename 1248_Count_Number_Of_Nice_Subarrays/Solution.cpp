#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

// cur - x = k
// cur - k = x
int Solution::numberOfSubarrays(vector<int>& nums, int k) {

	unordered_map<int, int> preCnt;
	int cur = 0;
	int result = 0;
	for (const auto& v : nums) {
		if (v & 1) {
			++cur;
		}
		if (cur == k) ++result;
		if (preCnt.count(cur - k)) {
			result += preCnt[cur-k];
		}
		++preCnt[cur];
	}
	return result;

}
