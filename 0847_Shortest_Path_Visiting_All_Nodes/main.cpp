#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1},{0,2,4},{1,3,4},{2},{1,2}};
	Solution* test = new Solution();
	cout << test->shortestPathLength(input) << endl;
	return 0;
}

