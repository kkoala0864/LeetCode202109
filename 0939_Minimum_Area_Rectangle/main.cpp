#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
	Solution *test = new Solution();
	cout << test->minAreaRect(input) << endl;
	return 0;
}
