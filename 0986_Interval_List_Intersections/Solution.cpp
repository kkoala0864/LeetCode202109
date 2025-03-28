#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

vector<vector<int>> Solution::intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
	int idx1 = 0;
	int idx2 = 0;
	vector<vector<int>> result;
	while (idx1 < firstList.size() && idx2 < secondList.size() && ((firstList[idx1][1] < secondList[idx2][0]) || (secondList[idx2][1] < firstList[idx1][0]))) {
		firstList[idx1][1] < secondList[idx2][0] ? ++idx1 : ++idx2;
	}
	while (idx1 < firstList.size() && idx2 < secondList.size()) {
		vector<int> vec1 = firstList[idx1];
		vector<int> vec2 = secondList[idx2];

		int front = max(vec1[0], vec2[0]);
		int end = min(vec1[1], vec2[1]);
		result.push_back({front, end});
		vec1[1] < vec2[1] ? ++idx1 : ++idx2;
		while (idx1 < firstList.size() && idx2 < secondList.size() && ((firstList[idx1][1] < secondList[idx2][0]) || (secondList[idx2][1] < firstList[idx1][0]))) {
			firstList[idx1][1] < secondList[idx2][0] ? ++idx1 : ++idx2;
		}
	}
	return result;
}
