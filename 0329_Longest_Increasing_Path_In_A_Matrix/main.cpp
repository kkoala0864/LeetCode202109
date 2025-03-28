#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0}, {1}, {5}, {5}};
	Solution *test = new Solution();
	cout << test->longestIncreasingPath(input) << endl;
	cout << test->longestIncreasingPath2(input) << endl;
	cout << test->topologicalSort(input) << endl;
	return 0;
}
