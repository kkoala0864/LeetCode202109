#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find3(vector<int>& root, int val) {
	if (root[val] == val) return val;
	return root[val] = find3(root, root[val]);
}

int Solution::findCircleNum3(vector<vector<int>>& isConnected) {
	vector<int> root;
	int result = isConnected.size();
	for (int i = 0 ; i < isConnected.size() ; ++i) root.emplace_back(i);

	for (int i = 0 ; i < isConnected.size() ; ++i) {
		for (int j = i + 1 ; j < isConnected.size() ; ++j) {
			if (isConnected[i][j] == 1) {
				int ir = find3(root, i);
				int jr = find3(root, j);
				if (ir == jr) continue;
				--result;
				root[ir] = root[jr] = min(ir, jr);
			}
		}
	}
	return result;
}
