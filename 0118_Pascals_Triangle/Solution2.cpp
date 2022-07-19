#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::generate2(int numRows) {
	vector<vector<int>> result;
	vector<int> local;
	for (int i = 0 ; i < numRows ; ++i) {
		for (int j = i-1 ; j > 0 ; --j) {
			local[j] += local[j-1];
		}
		local.emplace_back(1);
		result.emplace_back(local);
	}
	return result;
}
