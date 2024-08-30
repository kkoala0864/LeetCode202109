#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

int Solution::pathSum(vector<int>& nums) {
	unordered_map<int, unordered_map<int, int>> tree;

	for (auto& v : nums) {
		int val = v % 10;
		v /= 10;
		int idx = v % 10;
		v /= 10;
		int lvl = v % 10;
		tree[lvl][idx-1] = val;
	}
	int i = 1;
	int result = 0;
	for (; i <= 5 ; ++i) {
		if (tree.count(i) == 0) break;
		for (const auto& e : tree[i]) {
			if (tree.count(i+1) == 0) {
				result += e.second;
			} else {
				bool find = false;
				if (tree[i+1].count(e.first*2)) {
					find = true;
					tree[i+1][e.first*2] += e.second;
				}
				if (tree[i+1].count(e.first*2 + 1)) {
					find = true;
					tree[i+1][e.first*2+1] += e.second;
				}
				if (!find) result += e.second;
			}
		}
	}

	return result;
}
