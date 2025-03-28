#include <Solution.h>
#include <iostream>
#include <cmath>

using namespace std;

int Solution::singleNumber(vector<int> &nums) {
	int result = 0;
	for (int i = 0; i < 32; ++i) {
		int cnt = 0;
		for (const auto &num : nums) {
			int p = abs(num);
			cnt += ((p >> i) & 1);
		}
		cnt = cnt % 3;
		result += (cnt * pow(2, i));
	}
	int c = 0;
	for (const auto &num : nums) {
		if (num == result)
			++c;
	}
	return c == 1 ? result : -1 * result;
}
