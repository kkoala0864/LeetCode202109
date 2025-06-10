#include <data_type.h>

class BTree {
	public :
		void update(long long vi, long long v, long long tl, long long tr) {
			if (tl == tr) {
				val += v;
				return;
			}
			long long mid = tl + ((tr - tl) >> 1);
			if (vi <= mid) {
				if (left == nullptr) left = new BTree();
				left->update(vi, v, tl, mid);
			} else {
				if (right == nullptr) right = new BTree();
				right->update(vi, v, mid + 1, tr);
			}
			val = (left ? left->val : 0) + (right ? right->val : 0);
		}
		long long query(long long vl, long long vr, long long tl, long long tr) {
			if (vr < tl || vl > tr) return 0;
			if (vl <= tl && tr <= vr) return val;
			long long mid = tl + ((tr - tl) >> 1);

			long long ret = 0;
			if (left) ret += left->query(vl, vr, tl, mid);
			if (right) ret += right->query(vl, vr, mid + 1, tr);
			return ret;
		}
	private :
		long long val = 0;
		BTree* left = nullptr;
		BTree* right = nullptr;
};

class Solution {
public:
	Solution() {
	}
	int countRangeSum(vector<int>& nums, int lower, int upper);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
