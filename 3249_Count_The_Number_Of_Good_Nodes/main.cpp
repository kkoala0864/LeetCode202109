#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8}};
	Solution *test = new Solution();
	cout << test->countGoodNodes(input) << endl;
	return 0;
}
