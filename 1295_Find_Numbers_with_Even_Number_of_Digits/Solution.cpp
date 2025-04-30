#include <Solution.h>
#include <string>

int Solution::findNumbers(vector<int>& nums) {
	int result = 0;
	for (const auto& v : nums) {
		string s = to_string(v);
		if (s.size() & 1) continue;
		++result;
	}
	return result;
}
