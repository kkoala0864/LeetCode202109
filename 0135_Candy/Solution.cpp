#include <Solution.h>

int Solution::candy(vector<int> &ratings) {
	int size = ratings.size();
	vector<int> LToR(size, 1), RToL(size, 1);

	// compare with left side
	for (int i = 1 ; i < size ; ++i) {
		if (ratings[i] > ratings[i-1]) {
			LToR[i] = LToR[i-1] + 1;
		}
	}
	// compare with right side
	for (int i = size - 2 ; i >= 0 ; --i) {
		if (ratings[i] > ratings[i+1]) {
			RToL[i] = RToL[i+1] + 1;
		}
	}
	int result = 0;
	for (int i = 0 ; i < size ; ++i) {
		result += max(LToR[i], RToL[i]);
	}
	return result;
}
