#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
	Solution *test = new Solution();
	cout << test->minScore(4, input) << endl;
	return 0;
}
