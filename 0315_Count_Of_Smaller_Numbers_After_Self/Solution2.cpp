#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

class st {
	public:
		st() {
			_m = vector<int>(8 * 10001, 0);
		}
		void modify(int val, int idx, int l, int r) {
			if (l == r) ++_m[idx];
			else {
				int mid = (l + r) >> 1;
				if (val <= mid) modify(val, 2 * idx, l, mid);
				else modify(val, 2 * idx + 1, mid + 1, r);
				_m[idx] = _m[2 * idx] + _m[2 * idx + 1];
			}
		}

		int query(int idx, int ql, int qr, int l, int r) {
			if (ql > qr) return 0;
			if (ql == l && qr == r) return _m[idx];
			int mid = (l+r) >> 1;
			return query(2 * idx, ql, min(qr, mid), l, mid) + query(2 * idx + 1, max(ql, mid+1), qr, mid + 1, r);
		}
	private:
		vector<int> _m;
};

vector<int> Solution::countSmaller2(vector<int>& nums) {
	vector<int> result(nums.size(), 0);
	int offset = 1e4;
	int n = 2 * (offset + 1);
	st t;
	for (int i = nums.size() - 1 ; i >= 0 ; --i) {
		t.modify(nums[i] + offset, 1, 0, n - 1);
		result[i] = t.query(1, 0, nums[i] + offset-1, 0, n - 1);
	}
	return result;
}
