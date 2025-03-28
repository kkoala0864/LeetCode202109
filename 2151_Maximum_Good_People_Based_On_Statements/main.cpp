#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{2, 0}, {0, 2}};
	Solution *test = new Solution();
	cout << test->maximumGood(input) << endl;
	return 0;
}
