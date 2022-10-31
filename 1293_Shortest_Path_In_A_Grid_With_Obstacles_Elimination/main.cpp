#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> grid = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}};
	Solution* test = new Solution();
	cout << test->shortestPath(grid, 1) << endl;
	return 0;
}

