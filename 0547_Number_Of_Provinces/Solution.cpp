#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::cout;
using std::endl;

int find(vector<int>& c, int val) {
	if (c[val] == val) return val;
	return c[val] = find(c, c[val]);
}

int Solution::findCircleNum(vector<vector<int>>& isConnected) {
	vector<int> c;
	int cnt = isConnected.size();

	for (int i = 0 ; i < isConnected.size() ; ++i) c.emplace_back(i);

	for (int i = 0 ; i < isConnected.size() ; ++i) {
		for (int j = 0 ; j < isConnected[i].size() ; ++j) {
			if (isConnected[i][j] == 0) continue;

			int ir = find(c, i);
			int jr = find(c, j);
			if (ir == jr) continue;
			--cnt;
			c[ir] = c[jr] = min(ir, jr);
		}
	}
	return cnt;
}
