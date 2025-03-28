#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;
using std::pair;

int Solution::largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
	vector<pair<int, int>> vec1, vec2;
	int n = img1.size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (img1[i][j] == 1)
				vec1.emplace_back(pair<int, int>(i, j));
			if (img2[i][j] == 1)
				vec2.emplace_back(pair<int, int>(i, j));
		}
	}

	map<pair<int, int>, int> diffCnt;
	int result = 0;
	for (const auto &v1 : vec1) {
		for (const auto &v2 : vec2) {
			pair<int, int> key = pair<int, int>(v1.first - v2.first, v1.second - v2.second);
			++diffCnt[key];
			result = max(result, diffCnt[key]);
		}
	}
	return result;
}
