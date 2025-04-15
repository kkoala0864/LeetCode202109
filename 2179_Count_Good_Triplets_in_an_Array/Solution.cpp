#include <Solution.h>
#include <iostream>
#include <set>
#include <vector>

long long Solution::goodTriplets(vector<int>& nums1, vector<int>& nums2) {
	vector<int> idx2(nums2.size(), 0);
	for (int i = 0 ; i < nums2.size() ; ++i) {
		idx2[nums2[i]] = i + 1;
	}

	int size = nums1.size();
	FTree t(size);

	long long result = 0;
	for (int i = 1 ; i < size - 1 ; ++i) {
		t.update(1, idx2[nums1[i-1]]);
		int vIdx2 = idx2[nums1[i]];
		long long preCnt = 0, postCnt = 0;
		if (vIdx2 > 1) preCnt = t.query(vIdx2 - 1);
		if (vIdx2 < size) {
			int postValidCnt = t.query(size) - t.query(vIdx2);
			// 0 1 2 3 4 5
			postCnt = size - vIdx2 - postValidCnt;
		}
		result += preCnt * postCnt;
	}
	return result;
}
