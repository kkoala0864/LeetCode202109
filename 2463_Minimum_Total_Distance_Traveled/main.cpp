#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,4,6};
	vector<vector<int>> factory = {{2,2},{6,2}};
	Solution *test = new Solution();
	cout << test->minimumTotalDistance(input, factory) << endl;
	return 0;
}
