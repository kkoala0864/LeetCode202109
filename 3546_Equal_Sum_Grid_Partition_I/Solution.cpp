#include <Solution.h>

bool Solution::canPartitionGrid(vector<vector<int>>& grid) {
	unordered_set<long long> vps, hps;
	int m = grid.size(), n = grid[0].size();

	long long sum = 0;
	for (int i = 0 ; i < m ; ++i) {
		for (int j = 0 ; j < n ; ++j) {
			sum += (long long)grid[i][j];
		}
		hps.emplace(sum);
	}
	if (sum & 1) return false;
	if (hps.count(sum >> 1)) return true;

	sum = 0;
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j < m ; ++j) {
			sum += (long long)grid[j][i];
		}
		vps.emplace(sum);
	}
	return vps.count(sum >> 1);

}
