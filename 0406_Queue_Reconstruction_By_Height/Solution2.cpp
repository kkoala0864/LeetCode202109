#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

vector<vector<int>> Solution::reconstructQueue2(vector<vector<int>>& people) {
	sort(people.begin(), people.end());

	for (int i = people.size() - 1 ; i >= 0 ; --i) {
		int curVal = people[i][0];
		int curCnt = people[i][1];
		int cnt = 0;
		for (int j = i-1 ; j >= 0 ; --j) {
			if (people[j][0] >= people[i][0]) ++cnt;
			else break;
		}
		int idx = i;
		while (cnt < curCnt && idx < people.size() - 1) {
			swap(people[idx], people[idx+1]);
			++cnt;
			++idx;
		}
	}
	return people;
}
