#include <Solution.h>

int Solution::maximumEnergy(vector<int> &energy, int k) {
	int result = INT_MIN;

	for (int i = 0 ; i < k ; ++i) {
		int cur = 0;
		for (int j = energy.size() - 1 - i ; j >= 0 ; j -= k) {
			cur += energy[j];
			result = max(result, cur);
		}
	}
	return result;
}
