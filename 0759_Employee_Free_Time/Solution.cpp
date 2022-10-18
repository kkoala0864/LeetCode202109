#include <Solution.h>
#include <iostream>
#include <map>
#include <climits>

using std::map;

// 1  :  1     1
// 2  :  2     3
// 3  :  -1    2
// 4  : -1     1
// 5  :  -1    0   lastZero = 5
// 6  : 1      1   (5, 6)
// 7  :  -1    0   lastZero = 7
// 9  : 1      1   (7, 9)
// 12 : -1     0    lastZero = 12

// TC : O(nlogn)  SC : O(2n)
vector<Interval> Solution::employeeFreeTime(vector<vector<Interval>> schedule) {
	map<int, int> timeline;

	for (const auto& person : schedule) {
		for (const auto& t : person) {
			++timeline[t.start];
			--timeline[t.end];
		}
	}

	int lastZero = INT_MIN;
	vector<Interval> result;

	int curSum = 0;
	for (const auto& t : timeline) {
		if (curSum == 0 && lastZero != INT_MIN) {
			result.emplace_back(Interval(lastZero, t.first));
		}
		curSum += t.second;
		if (curSum == 0) lastZero = t.first;
	}
	return result;
}
