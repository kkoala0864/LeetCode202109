#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	vector<vector<int>> input = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
	cout << test->countPairs(7, input) << endl;
	return 0;
}
