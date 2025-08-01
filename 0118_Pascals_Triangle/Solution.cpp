#include <Solution.h>

vector<vector<int>> Solution::generate(int numRows) {
	vector<vector<int>> result;
	vector<int> cur(1,1);
	result.emplace_back(cur);
	for (int i = 1 ; i < numRows ; ++i) {
		vector<int> next(1, 1);
		for (int j = 0 ; j < cur.size() - 1 ; ++j) {
			next.emplace_back(cur[j] + cur[j+1]);
		}
		next.emplace_back(1);
		result.emplace_back(next);
		cur = std::move(next);
	}
	return result;
}
