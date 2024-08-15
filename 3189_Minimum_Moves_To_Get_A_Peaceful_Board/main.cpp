#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,0},{0,2},{2,3},{1,3},{1,2}};
	Solution* test = new Solution();
	cout << test->minMoves(input) << endl;
	return 0;
}

