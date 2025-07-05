#include <Solution.h>

int Solution::maxJump(vector<int>& stones) {
	if (stones.size() == 2) return stones.back() - stones[0];

	int result = 0;
	for (int i = 0 ; i < stones.size() - 2 ; ++i) {
		result = max(result, stones[i+2] - stones[i]);
	}
	return result;
}
