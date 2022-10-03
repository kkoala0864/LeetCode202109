#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::minCost(string colors, vector<int>& neededTime) {
	int result = 0;
	int size = colors.size();
	for (int i = 0 ; i < size ; ++i) {
		if (i < size - 1 && colors[i] == colors[i+1]) {
			int maxVal = neededTime[i];
			int timeSum = neededTime[i];
			while (i < size - 1 && colors[i] == colors[i+1]) {
				++i;
				maxVal = max(neededTime[i], maxVal);
				timeSum += neededTime[i];
			}
			result += (timeSum - maxVal);
		}
	}
	return result;
}
