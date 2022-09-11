#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::sort;
using std::map;
using std::cout;
using std::endl;

int Solution::minGroups(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end());
	map<int, int> groups;
	int result = 0;
	for (auto& i : intervals) {
		auto it = groups.lower_bound(i[0]);
		if (!groups.empty() && it != groups.begin()) {
			--it;
			--it->second;
			--result;
			if (it->second == 0) groups.erase(it->first);
		}
		++groups[i[1]];
		++result;
	}
	return result;
}
