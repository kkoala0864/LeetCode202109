#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::map;
using std::min;

// find longest increasing sequence
vector<int> Solution::longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
	vector<int> list;
	vector<int> result;

	for (const auto &v : obstacles) {
		int idx = upper_bound(list.begin(), list.end(), v) - list.begin();
		if (idx == list.size())
			list.emplace_back(v);
		else
			list[idx] = v;
		result.emplace_back(idx + 1);
	}
	return result;
}
