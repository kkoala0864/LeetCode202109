#include <Solution.h>

int Solution::evenNumberBitwiseORs(vector<int>& nums) {
	int result = 0;
	for (const auto& v : nums) {
		if (v & 1) continue;
		result = result | v;
	}
	return result;
}
