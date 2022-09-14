#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::cout;
using std::endl;

int find2(vector<int>& root, int val) {
	if (root[val] == val) return val;
	return root[val] = find2(root, root[val]);
}

int Solution::makeConnected2(int n, vector<vector<int>>& connections) {
	vector<int> root;
	for (int i = 0 ; i < n ; ++i) root.emplace_back(i);
	int removeCnt = 0;
	int groupCnt = n;

	vector<vector<int>> con(n, vector<int>());
	for (const auto& c : connections) {
		int lr = find2(root, c[0]);
		int rr = find2(root, c[1]);
		if (lr == rr) {
			++removeCnt;
			continue;
		}
		root[lr] = root[rr] = min(lr, rr);
		--groupCnt;
	}
	return groupCnt == 1 ? 0 : removeCnt >= groupCnt - 1 ? groupCnt - 1 : -1;
}
