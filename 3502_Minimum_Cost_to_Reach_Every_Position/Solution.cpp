#include <Solution.h>
#include <iostream>

vector<int> Solution::minCosts(vector<int> &cost) {
	for (int i = 1; i < cost.size(); ++i) {
		cost[i] = min(cost[i], cost[i - 1]);
	}
	return cost;
}
