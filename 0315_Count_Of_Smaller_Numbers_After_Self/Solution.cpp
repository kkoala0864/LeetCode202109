#include <Solution.h>
#include <iostream>

class sTree {
	vector<int> segTree;
	inline static int n;

public:
	sTree(int n)
	    : segTree(4 * n) {
		this->n = n;
	}

	void update(int x, int i = 1, int l = 0, int r = n - 1) {
		if (l == r)
			segTree[i]++;
		else {
			int mid = (l + r) >> 1;
			if (x <= mid)
				update(x, i * 2, l, mid);
			else
				update(x, i * 2 + 1, mid + 1, r);
			segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
		}
	}

	int query(int xr, int xl = 0, int i = 1, int l = 0, int r = n - 1) {
		if (xl > xr)
			return 0;
		if (xl == l && xr == r)
			return segTree[i];

		int mid = (l + r) >> 1;
		return query(min(xr, mid), xl, 2 * i, l, mid) + query(xr, max(xl, mid + 1), 2 * i + 1, mid + 1, r);
	}
};

int findMinBigEqualThanMe(vector<int> &list, int val) {
	int start = 0, end = list.size() - 1;
	int mid = 0;
	while (start <= end) {
		mid = (end - start) / 2 + start;
		if (list[mid] < val) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return start < list.size() && list[start] >= val ? start : -1;
}

vector<int> Solution::countSmaller(vector<int> &nums) {
	vector<int> result(nums.size(), 0);
	vector<int> list(1, nums.back());
	for (int i = nums.size() - 2; i >= 0; --i) {
		int idx = findMinBigEqualThanMe(list, nums[i]);
		result[i] = idx == -1 ? list.size() : idx;
		if (idx == -1)
			list.emplace_back(nums[i]);
		else
			list.insert(list.begin() + idx, nums[i]);
	}
	return result;
}

vector<int> Solution::SegTree(vector<int> &nums) {
	sTree t(2 * (1e4 + 1));
	for (int i = nums.size() - 1; i >= 0; --i) {
		t.update(nums[i] + (1e4 + 1));
		nums[i] = t.query(nums[i] + 1e4);
	}
	return nums;
}
