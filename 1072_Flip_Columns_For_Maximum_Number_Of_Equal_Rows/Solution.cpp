#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using std::max;
using std::string;
using std::unordered_map;

int Solution::maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
	unordered_map<string, int> um;
	int result = 0;
	for (const auto &m : matrix) {
		bool flip = m[0] == 1;
		string s;
		for (const auto &i : m) {
			if (flip) {
				s.push_back((i == 0 ? 1 : 0) + '0');
			} else
				s.push_back(i + '0');
		}
		++um[s];
		result = max(result, um[s]);
	}
	return result;
}
