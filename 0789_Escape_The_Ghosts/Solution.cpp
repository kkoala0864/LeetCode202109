#include <Solution.h>

bool Solution::escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
	long long dis = abs(target[0]) + abs(target[1]);

	for (const auto& g : ghosts) {
		long long gx = abs(target[0] - g[0]);
		long long gy = abs(target[1] - g[1]);
		long long gdis = gx + gy;
		if (gdis <= dis) {
			return false;
		}
	}
	return true;
}
