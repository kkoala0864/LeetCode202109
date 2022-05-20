#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class sTree {
	vector<int> segTree;
	inline static int n;

	public:
	sTree(int n) : segTree(4*n) {
		this->n = n;
	}

	void update(int x, int i = 1, int l = 0, int r = n-1) {
		if (l == r) segTree[i]++;
		else {
			int mid = (l+r) >> 1;
			if (x <= mid) update(x, i * 2, l, mid);
			else update(x, i * 2 + 1, mid + 1, r);
			segTree[i] = segTree[2*i] + segTree[2*i+1];
		}
	}

	int query(int xr, int xl = 0, int i = 1, int l = 0, int r = n-1) {
		if (xl > xr) return 0;
		if (xl == l && xr == r) return segTree[i];

		int mid = (l+r) >> 1;
		return query(min(xr, mid), xl, 2 * i, l, mid) + query(xr, max(xl, mid+1), 2*i+1, mid+1, r);
	}
};

class Solution {
    public :
        Solution() {}
	vector<int> SegTree(vector<int>& nums);
	vector<int> countSmaller(vector<int>& nums);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

