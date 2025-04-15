#include <Solution.h>
#include <iostream>
#include <set>
#include <vector>

long long Solution::goodTriplets(vector<int>& nums1, vector<int>& nums2) {
	vector<int> idx2(nums2.size(), 0);
	for (int i = 0 ; i < nums2.size() ; ++i) {
		idx2[nums2[i]] = i;
	}

	int size = nums1.size();
	BTree t(size);

	long long result = 0;
	for (int i = 1 ; i < size - 1 ; ++i) {
		t.set(1, idx2[nums1[i-1]], 1, 0, size - 1);
		int vIdx2 = idx2[nums1[i]];
		long long preCnt = 0, postCnt = 0;
		if (vIdx2 > 0) preCnt = t.query(0, vIdx2 - 1, 1, 0, size - 1);
		if (vIdx2 < size - 1) {
			int postValidCnt = t.query(vIdx2 + 1, size - 1, 1, 0, size - 1);
			// 0 1 2 3 4 5
			postCnt = size - 1 - vIdx2 - postValidCnt;
		}
		result += preCnt * postCnt;
	}
	return result;
}
