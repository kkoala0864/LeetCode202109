#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 7;
	vector<vector<int>> input = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
	Solution* test = new Solution();
	cout << test->countPaths(n, input) << endl;
	return 0;
}

