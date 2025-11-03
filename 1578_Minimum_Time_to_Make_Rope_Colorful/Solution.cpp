#include <Solution.h>

int Solution::minCost(string colors, vector<int> &neededTime) {
	int cost = 0;

	int sum = neededTime[0];
	int lastMax = neededTime[0];
	int cnt = 1;
	for (int i = 1 ; i < colors.size() ; ++i) {
		sum += neededTime[i];
		if (colors[i] == colors[i-1]) {
			++cnt;
			lastMax = max(lastMax, neededTime[i]);
		} else {
			cost += lastMax;
			cnt = 1;
			lastMax = neededTime[i];
		}
	}
	cost += lastMax;
	return sum - cost;
}
