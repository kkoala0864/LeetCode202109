#include <data_type.h>
#include <vector>
#include <climits>

using namespace std;

class BTree {
	public :
		BTree() {
			this->val = INT_MAX;
			left = right = nullptr;
		}

		void update(int idx, int val, BTree*& node, int tl, int tr) {
			if (!node) {
				node = new BTree();
			}
			if (tl == tr) {
				node->val = min(val, node->val);
				return;
			}
			int mid = tl + ((tr - tl) >> 1);

			if (idx <= mid) {
				update(idx, val, node->left, tl, mid);
			} else {
				update(idx, val, node->right, mid + 1, tr);
			}
			int lv = node->left ? node->left->val : INT_MAX;
			int rv = node->right ? node->right->val : INT_MAX;
			node->val = min(lv, rv);
		}

		int query(int vl, int vr, BTree* node, int tl, int tr) {
			if (!node || vr < tl || tr < vl) return INT_MAX;
			if (vl <= tl && tr <= vr) return node->val;

			int mid = tl + ((tr - tl) >> 1);
			return min(query(vl, vr, node->left, tl, mid), query(vl, vr, node->right, mid + 1, tr));
		}

		BTree *left;
		BTree *right;
		int val;
};

class Solution {
public:
	Solution() {
	}
	vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
