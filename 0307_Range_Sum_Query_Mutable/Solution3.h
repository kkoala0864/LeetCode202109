#include <vector>
#include <algorithm>
#include <vector>

using std::vector;
using std::min;
using std::max;

class NumArray {
	public :
		void modify(int qi, int val, int i, int l, int r) {
			if (l == r) ++_m[i] = val;
			else {
				int mid = (l + r) >> 1;
				if (mid >= qi) {
					modify(qi, val, 2 * i, l, mid);
				} else {
					modify(qi, val, 2 * i + 1, mid + 1, r);
				}
				_m[i] = _m[2*i] + _m[2*i+1];
			}
		}

		int query(int i, int ql, int qr, int l, int r) {
			if (ql > qr) return 0;
			if (ql == l && qr == r) {
				return _m[i];
			}
			int mid = (l + r) >> 1;
			return query(2 * i, ql, min(qr, mid), l, mid) + query(2 * i + 1, max(ql, mid + 1), qr, mid + 1, r);
		}

		NumArray(vector<int>& nums) {
			size = nums.size();
			_m = vector<int>(4 * size);
			for (int i = 0 ; i < size ; ++i) {
				modify(i, nums[i], 1, 0, size-1);
			}
		}

		void update(int index, int val) {
			modify(index, val, 1, 0, size - 1);
		}

		int sumRange(int left, int right) {
			return query(1, left, right, 0, size - 1);
		}
	private :
		vector<int> _m;
		int size;
		virtual ~NumArray() {}
		NumArray& operator=(const NumArray& source);
		NumArray(const NumArray&);
};

