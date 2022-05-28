#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::min;
using std::max;

vector<vector<int>> Solution::reconstructQueue(vector<vector<int>>& people) {
	auto cmp = [](vector<int>& lhs, vector<int>& rhs) { return lhs[1] == rhs[1] ? lhs[0] < rhs[0] : lhs[1] < rhs[1]; };

	sort(people.begin(), people.end(), cmp);
	for (int i = 0 ; i < people.size() ; ++i) {
		int curVal = people[i][0];
		int curCnt = people[i][1];
		int cnt = 0;
		for (int j = 0 ; j < i ; ++j) {
			if (people[j][0] >= curVal) ++cnt;
		}
		int idx = i;
		while (cnt > curCnt) {
			if (people[idx][0] <= people[idx-1][0]) --cnt;
			swap(people[idx], people[idx-1]);
			--idx;
		}
	}
	return people;
}
