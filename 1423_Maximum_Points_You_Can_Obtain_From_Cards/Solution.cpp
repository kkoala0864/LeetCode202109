#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxScore(vector<int> &cardPoints, int k) {
	int sum = 0;
	for (int i = 0; i < k; ++i)
		sum += cardPoints[i];

	int result = sum;
	for (int i = 0; i < k; ++i) {
		sum = sum - cardPoints[k - 1 - i] + cardPoints[cardPoints.size() - 1 - i];
		result = max(sum, result);
	}
	return result;
}
