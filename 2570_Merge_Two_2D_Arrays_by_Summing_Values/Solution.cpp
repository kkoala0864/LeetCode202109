#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

vector<vector<int>> Solution::mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
	vector<vector<int>> result;

	int i1 = 0, i2 = 0;
	while (i1 < nums1.size() || i2 < nums2.size()) {
		if (i2 >= nums2.size() || (i1 < nums1.size() && nums1[i1][0] < nums2[i2][0])) {
			result.emplace_back(vector<int>({nums1[i1][0], nums1[i1][1]}));
			++i1;
		} else if (i1 >= nums1.size() || (i2 < nums2.size() && nums1[i1][0] > nums2[i2][0])) {
			result.emplace_back(vector<int>({nums2[i2][0], nums2[i2][1]}));
			++i2;
		} else {
			result.emplace_back(vector<int>({nums1[i1][0], nums1[i1][1] + nums2[i2][1]}));
			++i1;
			++i2;
		}
	}
	return result;
}
