#include <Solution.h>

int Solution::findLongestChain(vector<vector<int>> &pairs) {
	auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
		return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
	};
	sort(pairs.begin(), pairs.end(), cmp);

	int result = 0;
	int last = INT_MIN;
	for (int i = 0 ; i < pairs.size() ; ++i) {
		if (pairs[i][0] > last) {
			++result;
			last = pairs[i][1];
		}
	}
	return result;
}
