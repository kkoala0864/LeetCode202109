#include <Solution.h>
#include <cmath>
#include <cfloat>

double calTime(const pair<int, int>& tires, int lap) {
	double f = tires.first, r = tires.second;
	return (f * (pow(r, lap) - 1)) / (r - 1);
}

// dp[i] = dp[i-j] + change time + minTime(j);

int Solution::minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};

	sort(tires.begin(), tires.end(), cmp);
	vector<pair<int, int>> tmp;
	for (int i = 0 ; i < tires.size() ; ++i) {
		if (!tmp.empty() && tmp.back().first < tires[i][0]) continue;
		tmp.emplace_back(pair<int, int>(tires[i][0], tires[i][1]));
	}

	vector<double> minTime(min(20, numLaps) + 1, DBL_MAX);
	for (int i = 1 ; i < minTime.size() ; ++i) {
		for (const auto& t : tmp) {
			minTime[i] = min(minTime[i], calTime(t, i));
		}
	}

	vector<double> dp(numLaps + 1, DBL_MAX);

	dp[0] = 0;

	for (int i = 1 ; i <= numLaps ; ++i) {
		for (int j = 1 ; j <= min(20, i) ; ++j) {
			dp[i] = min(dp[i], dp[i-j] + (i == j ? 0 : changeTime) + minTime[j]);
		}
	}
	return dp[numLaps];
}
