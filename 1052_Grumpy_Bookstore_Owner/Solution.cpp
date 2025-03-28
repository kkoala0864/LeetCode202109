#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
	int result = 0;

	int size = customers.size();
	int l = 0;
	int curG = 0;
	int maxG = 0;
	for (int i = 0; i < size; ++i) {
		if (grumpy[i] == 0)
			result += customers[i];
		else
			curG += customers[i];

		if (i >= minutes) {
			if (grumpy[l] == 1) {
				curG -= customers[l];
			}
			++l;
		}
		maxG = max(maxG, curG);
	}
	result += maxG;
	return result;
}
