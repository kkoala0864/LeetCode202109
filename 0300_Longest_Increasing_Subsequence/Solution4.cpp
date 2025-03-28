#include <Solution.h>
#include <iostream>
using std::cout;
using std::endl;

int Solution::lengthOfLIS4(vector<int> &nums) {
	vector<int> iv;
	for (auto v : nums) {
		auto it = lower_bound(iv.begin(), iv.end(), v);
		if (it == iv.end())
			iv.push_back(v);
		else
			*it = v;
	}
	return iv.size();
}
