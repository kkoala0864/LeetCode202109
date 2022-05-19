#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{9,9,4},{6,6,8},{2,1,1}};
	Solution* test = new Solution();
	cout << test->longestIncreasingPath(input) << endl;
	cout << test->topologicalSort(input) << endl;
	return 0;
}

