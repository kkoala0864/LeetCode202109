#include <Solution.h>
#include <iostream>

vector<vector<int>> Solution::generate(int numRows) {
	vector<vector<int>> result = {{1}};
	vector<int> local;
	for (int i = 1; i < numRows; ++i) {
		local.clear();
		for (int j = 0; j < (i + 1); ++j) {
			if (j == 0 || j == i) {
				local.emplace_back(1);
			} else {
				local.emplace_back(result[i - 1][j - 1] + result[i - 1][j]);
			}
		}
		result.emplace_back(local);
	}
	return result;
}
