#include <Solution.h>
#include <iostream>

int Solution::minDeletionSize(vector<string>& strs) {
	vector<bool> del(strs.size(), false);
	int result = 0;
	for (int i = 1 ; i < strs.size() ; ++i) {
		for (int j = 0 ; j < strs[i].size() ; ++j) {
			if (del[j]) continue;
			if (strs[i][j] < strs[0][j]) {
				del[j] = true;
				++result;
			} else {
				strs[0][j] = strs[i][j];
			}
		}
	}
	return result;
}
