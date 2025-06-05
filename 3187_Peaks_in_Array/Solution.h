#include <data_type.h>

class BTree{
	public :
		BTree(int size) {
			tree = vector<int>(4 * size + 1, 0);
		}
		void update(int vi, int val, int ti, int tl, int tr) {
			if (tl == tr) {
				tree[ti] = val;
				return;
			}

			int mid = tl + ((tr - tl) >> 1);
			if (vi <= mid) {
				update(vi, val, ti * 2, tl, mid);
			} else {
				update(vi, val, ti * 2 + 1, mid + 1, tr);
			}
			tree[ti] = tree[ti*2] + tree[ti * 2 + 1];
		}

		int query(int vl, int vr, int ti, int tl, int tr) {
			if (tl > vr || vl > tr) return 0;
			if (vl <= tl && tr <= vr) return tree[ti];

			int mid = tl + ((tr - tl) >> 1);
			return query(vl, vr, 2 * ti, tl, mid) + query(vl, vr, 2 * ti + 1, mid + 1, tr);
		}

	private :
		vector<int> tree;
};

class Solution {
public:
	Solution() {
	}
	vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
