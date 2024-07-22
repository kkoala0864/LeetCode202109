#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::sort;

vector<string> Solution::sortPeople(vector<string>& names, vector<int>& heights) {
	vector<pair<int, int>> hToIdx;
	for (int i = 0 ; i < names.size() ; ++i) {
		hToIdx.emplace_back(pair<int, int>(heights[i], i));
	}
	sort(hToIdx.begin(), hToIdx.end(), std::greater<pair<int, int>>());

	vector<string> result;
	for (const auto& i : hToIdx) {
		result.emplace_back(names[i.second]);
	}
	return result;
}
