#include <Solution.h>
#include <iostream>
#include <climits>

int Solution::numTeams(vector<int>& rating) {
	int result = 0;

	vector<vector<int>> inc(rating.size(), vector<int>(3, 0));
	vector<vector<int>> dec(rating.size(), vector<int>(3, 0));

	for (int i = 0 ; i < rating.size() ; ++i) {
		for (int j = 0 ; j < i ; ++j) {
			if (rating[i] > rating[j]) {
				inc[i][2] += inc[j][1];
				result += inc[j][2];
			} else {
				dec[i][2] += dec[j][1];
				result += dec[j][2];
			}
		}
		inc[i][1] = 1;
		dec[i][1] = 1;
	}
	return result;
}
