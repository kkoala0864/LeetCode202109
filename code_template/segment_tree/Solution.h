#include <data_type.h>

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

class RangeTree {
	public :
		RangeTree(int size) {
			tree = vector<pair<int, int>>(4 * size + 4, pair<int, int>());
		}

		void apply(int ti, int tl, int tr, int v) {
			tree[ti].first += (v * (tr - tl + 1));
			tree[ti].second += v;
		}

		void push(int ti, int tl, int tr) {
			if (tree[ti].second == 0 || tl == tr) return;
			int m = tl + ((tr - tl) >> 1);
			apply(ti << 1, tl, m, tree[ti].second);
			apply((ti << 1) + 1, m + 1, tr, tree[ti].second);
			tree[ti].second = 0;
		}

		void rangeAdd(int vl, int vr, int v, int ti, int tl, int tr) {
			if ((vr < tl) || (tr < vl)) return;
			if (vl <= tl && tr <= vr) {
				apply(ti, tl, tr, v);
				return;
			}
			push(ti, tl, tr);
			int mid = tl + ((tr - tl) >> 1);
			rangeAdd(vl, vr, v, ti << 1, tl, mid);
			rangeAdd(vl, vr, v, (ti << 1) + 1, mid + 1, tr);
			tree[ti].first = tree[ti << 1].first + tree[(ti << 1) + 1].first;
		}

		int rangeSum(int vl, int vr, int ti, int tl, int tr) {
			if ((vr < tl) || (tr < vl)) return 0;
			if (vl <= tl && tr <= vr) {
				return tree[ti].first;
			}
			push(ti, tl, tr);
			int mid = tl + ((tr - tl) >> 1);
			return rangeSum(vl, vr, ti << 1, tl, mid) + rangeSum(vl, vr, (ti << 1) + 1, mid + 1, tr);
		}
	private:
		vector<pair<int, int>> tree;
};
