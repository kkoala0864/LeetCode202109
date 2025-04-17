#include <vector>

using namespace std;

class SegTree {
public:
	SegTree(int size) : tree(size * 4 + 1, 0) {}

	void update(int vi, int v, int ti, int tl, int tr) {
		if (tl == tr) {
			tree[ti] = v;
			return;
		}
		int mid = tl + ((tr - tl) >> 1);

		if (vi <= mid) {
			update(vi, v, ti << 1, tl, mid);
		} else {
			update(vi, v, (ti << 1) + 1, mid + 1, tr);
		}
		tree[ti] = tree[ti << 1] + tree[(ti << 1) + 1];
	}

	int query(int vl, int vr, int ti, int tl, int tr) {
		if ((vr < tl) || (vl > tr)) return 0;
		if (vl <= tl && tr <= vr) return tree[ti];

		int mid = tl + ((tr - tl) >> 1);
		return query(vl, vr, ti << 1, tl, mid) + query(vl, vr, (ti << 1) + 1, mid + 1, tr);
	}
private:
	vector<int> tree;
};
