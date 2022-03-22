#include <Solution.h>
#include <iostream>

vector<int> Solution::assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
	vector<vector<vector<int>>> record(2001, vector<vector<int>>());
	vector<int> result(workers.size(), -1);
	for (int i = 0 ; i < workers.size() ; ++i) {
		for (int j = 0 ; j < bikes.size() ; ++j) {
			int distance = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
			record[distance].push_back({i, j});
		}
	}

	int cnt = workers.size();
	vector<bool> bikeFlag(bikes.size(), false);
	for (int i = 0 ; i < record.size() ; ++i) {
		if (record[i].empty()) continue;
		for (int j = 0 ; j < record[i].size() ; ++j) {
			int bikeIdx = record[i][j][1];
			if (bikeFlag[bikeIdx]) continue;
			int workIdx = record[i][j][0];
			if (result[workIdx] == -1) {
				result[workIdx] = bikeIdx;
				bikeFlag[bikeIdx] = true;
				--cnt;
			}
			if (cnt == 0) break;
		}
	}
	return result;
}
