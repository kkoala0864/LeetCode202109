#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{1, 2, 3}, {2, 3, 4}, {2, 3, 5}};
	Solution *test = new Solution();
	cout << test->smallestCommonElement(input) << endl;
	return 0;
}
