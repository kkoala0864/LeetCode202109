#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1,2},{2,3},{3,4},{1,3}};
	Solution* test = new Solution();
	cout << test->eraseOverlapIntervals(input) << endl;
	return 0;
}

