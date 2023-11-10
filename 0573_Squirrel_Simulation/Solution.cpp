#include <Solution.h>
#include <iostream>
#include <climits>

int Solution::minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
	int nSize = nuts.size();
	int offset = INT_MIN;
	int result = 0;
	for (int i = 0 ; i < nSize ; ++i) {
		int tToNuts = abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]);
		int sToNuts = abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]);
		if (offset < (tToNuts - sToNuts)) {
			offset = tToNuts - sToNuts;
		}
		result += (2 * tToNuts);
	}
	result -= offset;
	return result;
}
