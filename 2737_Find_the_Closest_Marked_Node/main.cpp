#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 5;
	vector<vector<int>> input = {{0, 1, 2}, {0, 2, 4}, {1, 3, 1}, {2, 3, 3}, {3, 4, 2}};
	int s = 1;
	vector<int> marked = {0, 4};
	Solution *test = new Solution();
	cout << test->minimumDistance(n, input, s, marked) << endl;
	return 0;
}
