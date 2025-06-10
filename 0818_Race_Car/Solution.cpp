#include <Solution.h>

int Solution::racecar(int target) {
	vector<int> dp(target + 1, INT_MAX / 2);
	dp[0] = 0;

	for (int i = 1 ; i <= target ; ++i) {
		int k = 1;
		while (((1 << k) - 1) < i) ++k;
		int pk = (1 << k) - 1;

		if (pk == i) {
			dp[i] = k;
			continue;
		}

		dp[i] = k + 1 + dp[pk - i];

		int pkm1 = (1 << (k-1)) - 1;

		for (int m = 0 ; m < k-1 ; ++m) {
			int pm = (1 << m) - 1;
			int dist = i - (pkm1 - pm);
			if (dist < 0) continue;
			dp[i] = min(dp[i], (k - 1) + 1 + m + 1 + dp[dist]);
		}
	}
	return dp[target];
}

/*
int Solution::racecar(int target) {
	unordered_map<int, unordered_map<int, int>> minCost;

	priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

	pq.emplace(vector<int>({0, 0, 1}));
	minCost[0][1] = 0;

	while (!pq.empty()) {
		int curStep = pq.top()[0];
		int curIdx = pq.top()[1];
		int curSpeed = pq.top()[2];
		pq.pop();

		if (curIdx == target) return curStep;

		int frdIdx = curIdx + curSpeed;
		if (frdIdx >= -target && frdIdx <= 2*target) {
			if (minCost[frdIdx].count(curSpeed * 2) == 0) {
				minCost[frdIdx][curSpeed * 2] = INT_MAX;
			}
			if ((curStep + 1) < minCost[frdIdx][curSpeed * 2]) {
				minCost[frdIdx][curSpeed * 2] = curStep + 1;
				pq.emplace(vector<int>({curStep + 1, frdIdx, curSpeed * 2}));
			}
		}
		int rSpeed = curSpeed > 0 ? -1 : 1;
		if (minCost[curIdx].count(rSpeed) == 0) {
			minCost[curIdx][rSpeed] = INT_MAX;
		}
		if ((curStep + 1) < minCost[curIdx][rSpeed]) {
			minCost[curIdx][rSpeed] = curStep + 1;
			pq.emplace(vector<int>({curStep + 1, curIdx, rSpeed}));
		}
	}
	return -1;
}*/
