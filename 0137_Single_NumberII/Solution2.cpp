#include <Solution.h>
#include <iostream>

using namespace std;

int Solution::singleNumber2(vector<int>& nums) {
	int result = 0;
	for (int i = 0 ; i < 32 ; ++i) {
		int cnt = 0;
		for (const auto& v : nums) {
			cnt += ((v >> i) & 1);
		}
		cnt %= 3;
		result |= (cnt << i);
	}
	return result;
}
