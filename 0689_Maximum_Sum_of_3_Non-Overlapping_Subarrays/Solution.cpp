#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;

// 0 1 2 3 4 5
// 0 1
//   1 2
//     2 3
//       3 4
vector<int> Solution::maxSumOfThreeSubarrays(vector<int>& nums, int k) {
	vector<int> ksum;
	int sum = 0;
	for (int i = 0 ; i < nums.size() ; ++i) {
		sum += nums[i];
		if (i >= k) {
			sum -= nums[i-k];
		}
		if (i >= k-1) {
			ksum.emplace_back(sum);
		}
	}

	vector<int> dp;
	vector<vector<int>> pv;
	vector<int> curdp;
	vector<vector<int>> curlist;
	int v = INT_MIN;
	int idx = -1;
	for (int i = 0 ; i < ksum.size() ; ++i) {
		if (ksum[i] > v) {
			v = ksum[i];
			idx = i;
		}
		dp.emplace_back(v);
		pv.emplace_back(vector<int>({idx}));
	}

	for (int i = 1 ; i < 3 ; ++i) {
		int mv = INT_MIN;
		vector<int> list;
		for (int j = 0 ; j < ksum.size() ; ++j) {
			int v = 0;
			vector<int> l;
			if (j >= k) {
				v += dp[j-k];
				l = pv[j-k];
			}
			v += ksum[j];
			l.emplace_back(j);
			if (v > mv) {
				mv = v;
				list = l;
			}
			curdp.emplace_back(mv);
			curlist.emplace_back(list);
		}
		dp = move(curdp);
		pv = move(curlist);
	}
	return pv.back();
}
