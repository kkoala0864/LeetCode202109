#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 4;
	vector<vector<int>> input = {{0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}};
	Solution *test = new Solution();
	cout << test->checkValidCuts(n, input) << endl;
	return 0;
}
