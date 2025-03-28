#include <Solution.h>
#include <iostream>

// TC : O(nlogn);
// SC : O(1);
int Solution::maxIceCream(vector<int> &costs, int coins) {
	sort(costs.begin(), costs.end());

	int result = 0;
	for (int i = 0; i < costs.size(); ++i) {
		if (coins >= costs[i]) {
			++result;
			coins -= costs[i];
		} else {
			break;
		}
	}
	return result;
}
