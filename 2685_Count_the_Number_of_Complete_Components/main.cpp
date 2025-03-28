#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
	int n = 6;
	Solution *test = new Solution();
	cout << test->countCompleteComponents(n, input) << endl;
	return 0;
}
