#include <data_type.h>
#include <vector>

using namespace std;
class FTree {
	public:
		FTree(int size) {
			t = vector<int>(size + 1, 0);
		}

		void update(int val, int idx) {
			while (idx < t.size()) {
				t[idx] += val;
				idx += (idx & -idx);
			}
		}

		int query(int idx) {
			int ret = 0;
			while (idx > 0) {
				ret += t[idx];
				idx -= (idx & -idx);
			}
			return ret;
		}
	private:
		vector<int> t;
};

class BTree{
	public:
		BTree(int n) {
			t = vector<int>(n * 4 + 1, 0);
		}

		void set(int val, int i, int idx, int tl, int tr) {
			if (tl == tr && tl == i) {
				t[idx] += val;
				return;
			}

			int mid = tl + ((tr - tl) >> 1);
			if (i <= mid) {
				set(val, i, idx << 1, tl, mid);
			} else {
				set(val, i, (idx << 1) + 1, mid + 1, tr);
			}
			t[idx] = t[idx << 1] + t[(idx << 1) + 1];
		}

		int query(int vl, int vr, int idx, int tl, int tr) {
			if ((vr < tl) || (tr < vl)) return 0;
			if (vl <= tl && tr <= vr) return t[idx];

			int mid = tl + ((tr - tl) >> 1);
			return query(vl, vr, idx << 1, tl, mid) + query(vl, vr, (idx << 1) + 1, mid + 1, tr);
		}

	private:
		vector<int> t;
};

class Solution {
public:
	Solution() {
	}
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
