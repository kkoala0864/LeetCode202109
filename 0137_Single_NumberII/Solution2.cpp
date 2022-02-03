#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::singleNumber2(vector<int>& nums) {
	int result = 0;
	for (int j = 31 ; j >= 0 ; --j) {
		int cnt = 0;
		for (int i = 0 ; i < nums.size() ; ++i) {
			int val = nums[i];
			cnt += ((val >> j) & 1);
		}
		result = result << 1;
		result += (cnt % 3);
	}
	return result;
}
