#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

class NumArray {
public:
	void modify(int index, int val, int i = 1, int l = 0, int r = n - 1) {
		if (l == r)
			tree[i] = val;
		else {
			int mid = (l + r) >> 1;
			if (mid >= index)
				modify(index, val, 2 * i, l, mid);
			else
				modify(index, val, 2 * i + 1, mid + 1, r);
			tree[i] = tree[2 * i] + tree[2 * i + 1];
		}
	}

	int query(int ql, int qr, int i = 1, int l = 0, int r = n - 1) {
		if (ql > qr)
			return 0;
		if (ql == l && qr == r)
			return tree[i];

		int mid = (l + r) >> 1;
		return query(ql, min(qr, mid), 2 * i, l, mid) + query(max(ql, mid + 1), qr, 2 * i + 1, mid + 1, r);
	}

	NumArray(vector<int> &nums) {
		n = nums.size();
		tree = vector<int>(4 * nums.size());
		for (int i = 0; i < nums.size(); ++i) {
			modify(i, nums[i]);
		}
	}

	void update(int index, int val) {
		modify(index, val);
	}

	int sumRange(int left, int right) {
		return query(left, right);
	}

private:
	vector<int> tree;
	inline static int n;
	virtual ~NumArray() {
	}
	NumArray &operator=(const NumArray &source);
	NumArray(const NumArray &);
};
