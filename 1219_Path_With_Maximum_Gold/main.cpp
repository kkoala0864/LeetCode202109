#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
	Solution *test = new Solution();
	cout << test->getMaximumGold(input) << endl;
	return 0;
}
