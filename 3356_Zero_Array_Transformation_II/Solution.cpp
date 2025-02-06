#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::map;
using std::max;
using std::cout;
using std::endl;

int Solution::minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
	vector<int> offset(nums.size() + 1, 0);
	int cur = 0;
	int k = 0;

	for (int i = 0 ; i < nums.size() ; ++i) {
		while ((cur + offset[i]) < nums[i]) {
			if (k == queries.size()) return -1;

			int l = queries[k][0];
			int r = queries[k][1];
			int v = queries[k][2];
			++k;
			if (r < i) continue;
			offset[max(l, i)] += v;
			offset[r + 1] -= v;
		}
		cur += offset[i];
	}
	return k;

}


