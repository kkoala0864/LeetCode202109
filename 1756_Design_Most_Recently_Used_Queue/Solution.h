#include <data_type.h>
#include <vector>

using std::vector;

class FenwickTree {
public:
	FenwickTree(int size)
	    : tree(size + 1, 0) {
	}

	int sum(int idx) {
		int result = 0;
		while (idx > 0) {
			result += tree[idx];
			idx &= idx - 1;
		}
		return result;
	}

	void insert(int idx, int value) {
		++idx;
		while (idx < tree.size()) {
			tree[idx] += value;
			idx += (idx & -idx);
		}
	}

private:
	vector<int> tree;
};

class MRUQueue {
public:
	MRUQueue(int n)
	    : size(n), tree(n + 2000), values(n + 2000, 0) {
		for (int i = 0; i < n; ++i) {
			tree.insert(i, 1);
			values[i] = i + 1;
		}
	}

	int fetch(int k) {
		int low = 0, high = size;

		while (low < high) {
			int mid = low + ((high - low) >> 1);
			if (tree.sum(mid) < k) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		tree.insert(low - 1, -1);
		tree.insert(size, 1);
		values[size] = values[low - 1];
		++size;
		return values[low - 1];
	}

private:
	int size;
	FenwickTree tree;
	vector<int> values;
	virtual ~MRUQueue() {
	}
	MRUQueue &operator=(const MRUQueue &source);
	MRUQueue(const MRUQueue &);
};
