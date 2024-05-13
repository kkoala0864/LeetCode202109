#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int Solution::maximumEnergy(vector<int>& energy, int k) {
	int result = INT_MIN;

	for (int i = 0 ; i < k ; ++i) {
		int local = 0;
		for (int j = i ; j < energy.size() ; j += k) {
			if (local < 0) {
				local = 0;
			}
			local += energy[j];
		}
		result = max(result, local);
	}
	return result;
}
