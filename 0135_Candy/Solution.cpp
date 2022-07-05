#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::max;
using std::pair;

int Solution::twoArray(vector<int>& ratings) {
	vector<int> leftToRight(ratings.size(), 1), rightToLeft(ratings.size(), 1);

	for (int i = 0 ; i < ratings.size() - 1 ; ++i) {
		if (ratings[i] < ratings[i+1]) {
			leftToRight[i+1] = leftToRight[i] + 1;
		}

		if (ratings[ratings.size() - 1 - i] < ratings[ratings.size() - 2 - i]) {
			rightToLeft[ratings.size() - 2 - i] = rightToLeft[ratings.size() - 1 - i] + 1;
		}
	}

	int result = 0;
	for (int i = 0 ; i < ratings.size() ; ++i) {
		result += max(leftToRight[i], rightToLeft[i]);
	}
	return result;

}

int Solution::candy(vector<int>& ratings) {
	vector<int> c(ratings.size(), 1);
	vector<pair<int, int>> rl;
	for (int i = 0 ; i < ratings.size() ; ++i) {
		rl.emplace_back(pair<int, int>(ratings[i], i));
	}

	sort(rl.begin(), rl.end());
	int result = ratings.size();
	for (int i = 0 ; i < rl.size() - 1 ; ++i) {
		int idx = rl[i].second;
		if (idx - 1 >= 0) {
			if (ratings[idx-1] > ratings[idx]) {
				if (c[idx-1] < c[idx] + 1) {
					result = result - c[idx-1] + c[idx] + 1;
					c[idx-1] = c[idx] + 1;
				}
			}
		}
		if (idx + 1 < ratings.size()) {
			if (ratings[idx+1] > ratings[idx]) {
				if (c[idx+1] < c[idx] + 1) {
					result = result - c[idx+1] + c[idx] + 1;
					c[idx+1] = c[idx] + 1;
				}
			}
		}
	}
	return result;
}
