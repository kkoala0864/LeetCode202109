#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> source = {1, 2, 3, 4};
	vector<int> target = {2, 1, 4, 5};
	vector<vector<int>> allowedSwaps({{0, 1}, {2, 3}});
	Solution *test = new Solution();
	cout << test->minimumHammingDistance(source, target, allowedSwaps) << endl;
	return 0;
}
