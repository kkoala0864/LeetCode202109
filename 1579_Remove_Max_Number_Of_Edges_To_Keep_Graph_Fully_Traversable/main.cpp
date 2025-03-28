#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
	int n = 4;
	Solution *test = new Solution();
	cout << test->maxNumEdgesToRemove(n, input) << endl;
	return 0;
}
