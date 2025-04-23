#include <data_type.h>
#include <vector>

using namespace std;

class BTree {
	public :
		BTree(int size) {
			tree = vector<int>(size * 4 + 1, 0);
		}

		void update(int idx, int val, int ti, int tl, int tr) {
			if (tl == tr) {
				tree[ti] += val;
				return;
			}

			int mid = tl + ((tr - tl) >> 1);
			if (idx <= mid) {
				update(idx, val, ti << 1, tl, mid);
			} else {
				update(idx, val, (ti << 1) + 1, mid + 1, tr);
			}
			tree[ti] = tree[ti << 1] + tree[(ti << 1) + 1];
		}

		int query(int vl, int vr, int ti, int tl, int tr) {
			if ((tr < vl) || (vr < tl)) return 0;
			if (vl <= tl && tr <= vr) return tree[ti];
			int mid = tl + ((tr - tl) >> 1);

			return query(vl, vr, ti << 1, tl, mid) + query(vl, vr, (ti << 1) + 1, mid + 1, tr);
		}

	private :
		vector<int> tree;
};

class Solution {
public:
	Solution() {
	}
	int createSortedArray(vector<int>& instructions);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
