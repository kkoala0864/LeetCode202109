#include <data_type.h>
#include <vector>
#include <algorithm>
#include <iostream>

using std::max;
using std::vector;
using std::cout;
using std::endl;

class STree {
	public:
		STree(int size) {
			tree = vector<int>(size * 4 + 1, 0);
		}

		void update(int ti, int val, int vi, int vs, int ve) {
			if (vs == ve) {
				tree[ti] = max(tree[ti], val);
				return;
			}
			int mid = vs + ((ve - vs) >> 1);

			if (vi <= mid) {
				update(ti << 1, val, vi, vs, mid);
			} else {
				update((ti << 1) + 1, val, vi, mid + 1, ve);
			}
			tree[ti] = max(tree[ti << 1], tree[(ti << 1) + 1]);
		}

		int query(int ti, int ql, int qr, int vs, int ve) {
			if (qr < vs || ql > ve) return 0;
			if (ql <= vs && ve <= qr) {
				return tree[ti];
			}
			int mid = vs + ((ve - vs) >> 1);
			return  max(query(ti << 1, ql, qr, vs, mid),
					query((ti << 1) + 1, ql, qr, mid + 1, ve));
		}
	private:
		vector<int> tree;
};

class Solution {
    public :
        Solution() {}
	int lengthOfLIS(vector<int>& nums, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

