#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> grid = {{5,3},{4,0},{2,1}};
	vector<vector<int>> cost = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
	Solution* test = new Solution();
	cout << test->minPathCost(grid, cost) << endl;
	return 0;
}

