#include <Solution.h>

bool Solution::threeConsecutiveOdds(vector<int>& arr) {
	int cnt = 0;

	for (const auto& v : arr) {
		if ((v & 1) == 0) {
			cnt = 0;
		} else {
			++cnt;
		}
		if (cnt == 3) return true;
	}
	return false;
}
