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
		STree(vector<int>& datas) {
			n = datas.size();
			tree = vector<int>(4 * n + 1, 0);
			build(datas, 1, 0, n - 1);
		};

		void build(vector<int>& datas, int idx, int start, int end) {
			if (start == end) {
				tree[idx] = datas[start];
				return;
			}

			int mid = start + ((end - start) >> 1);
			build(datas, idx * 2, start, mid);
			build(datas, idx * 2 + 1, mid + 1, end);

			tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
		}

		void set(int val, int di, int idx, int start, int end) {
			if (start == end) {
				tree[idx] = val;
				return;
			}
			int mid = start + ((end - start) >> 1);

			if (mid >= di) {
				set(val, di, idx * 2, start, mid);
			} else {
				set(val, di, idx * 2 + 1, mid + 1, end);
			}
			tree[idx] = max(tree[idx*2], tree[idx*2 + 1]);
		}

		int query(int x) {
			if (tree[1] < x) return -1;
			return query_util(1, 0, n-1, x);
		}

		int query_util(int idx, int start, int end, int x) {
			if (start == end) return start;

			int mid = start + ((end - start) >> 1);

			if (tree[idx*2] >= x) return query_util(idx * 2, start, mid, x);
			else return query_util(idx * 2 + 1, mid + 1, end, x);
		}
	private:
		int n;
		vector<int> tree;
};

class Solution {
    public :
        Solution() {}
	int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

