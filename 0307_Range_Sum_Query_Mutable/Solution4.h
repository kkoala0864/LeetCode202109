#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::min;
using std::vector;

struct SNode
{
	int start;
	int end;
	int sum;
	SNode *left;
	SNode *right;

	SNode(int s, int e, int sum)
	    : start(s), end(e), sum(sum) {
	}
	SNode(int s, int e, int sum, SNode *l, SNode *r)
	    : start(s), end(e), sum(sum) {
		left = l;
		right = r;
	}
};

class NumArray {
public:
	SNode *build(int start, int end, const vector<int> &vec) {
		if (start == end) {
			auto node = new SNode(start, end, vec[start]);
			return node;
		}
		int mid = start + ((end - start) >> 1);

		auto l = build(start, mid, vec);
		auto r = build(mid + 1, end, vec);
		auto node = new SNode(start, end, l->sum + r->sum, l, r);
		return node;
	}

	void modify(SNode *node, int idx, int val) {
		if (node->start == node->end && node->start == idx) {
			node->sum = val;
			return;
		}

		int mid = node->start + ((node->end - node->start) >> 1);
		if (idx <= mid) {
			modify(node->left, idx, val);
		} else {
			modify(node->right, idx, val);
		}
		node->sum = node->left->sum + node->right->sum;
	}

	int query(SNode *node, int l, int r) {
		if (node->start == l && node->end == r) {
			return node->sum;
		}

		int mid = node->start + ((node->end - node->start) >> 1);
		if (r <= mid) {
			return query(node->left, l, r);
		} else if (l > mid) {
			return query(node->right, l, r);
		} else {
			return query(node->left, l, mid) + query(node->right, mid + 1, r);
		}
	}

	NumArray(vector<int> &nums) {
		size = nums.size();
		root = build(0, size - 1, nums);
	}

	void update(int index, int val) {
		modify(root, index, val);
	}

	int sumRange(int left, int right) {
		return query(root, left, right);
	}

private:
	SNode *root;
	int size;
	virtual ~NumArray() {
	}
	NumArray &operator=(const NumArray &source);
	NumArray(const NumArray &);
};
