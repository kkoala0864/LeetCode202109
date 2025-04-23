#include <vector>

using namespace std;

class fenwickTree {
public:
	fenwickTree(int size)
	    : tree(size + 1, 0) {
	}

	int query(int idx) {
		++idx;
		int result = 0;
		while (idx > 0) {
			result += tree[idx];
			idx -= (idx & -idx);
		}
		return result;
	}

	void update(int idx, int v) {
		++idx;
		while (idx < tree.size()) {
			tree[idx] += v;
			idx += (idx & -idx);
		}
	}

private:
	vector<int> tree;
};
