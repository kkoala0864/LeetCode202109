#include <vector>
#include <algorithm>
#include <vector>

using std::vector;
using std::min;
using std::max;

class NumArray {
    public :
	    void modify(int idx, int v, int i, int l, int r) {
		if (l == r) _t[i] = v;
		else {
			int mid = (l+r) >> 1;
			if (mid >= idx) {
				modify(idx, v, 2 * i, l, mid);
			} else {
				modify(idx, v, 2 * i + 1, mid+1, r);
			}
			_t[i] = _t[2*i] + _t[2*i+1];
		}
	    }

	    int query(int left, int right, int i, int l, int r) {
		    if (left > right) return 0;
		    if (left == l && right == r) return _t[i];
		    int mid = (l+r) >> 1;
		    return query(left, min(right, mid), 2 * i, l, mid) + query(max(left, mid+1), right, 2 * i + 1, mid + 1, r);
	    }

	    NumArray(vector<int>& nums) {
		    n = nums.size();
		    _t = vector<int>(n * 4, 0);
		    for (int i = 0 ; i < nums.size() ; ++i) {
			modify(i, nums[i], 1, 0, n-1);
		    }
	    }

	    void update(int index, int val) {
		modify(index, val, 1, 0, n-1);
	    }

	    int sumRange(int left, int right) {
		return query(left, right, 1, 0, n-1);
	    }
    private :
	    vector<int> _t;
	    int n;
	    virtual ~NumArray() {}
	    NumArray& operator=(const NumArray& source);
	    NumArray(const NumArray&);
};

