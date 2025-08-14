#include <Solution.h>

int Solution::maxBalancedShipments(vector<int>& weight) {
	int result = 0;
	int curMax = 0;
	for (int i = 0 ; i < weight.size() ; ++i) {
		curMax = max(curMax, weight[i]);
		if (weight[i] < curMax) {
			++result;
			curMax = 0;
		}
	}
	return result;

}
