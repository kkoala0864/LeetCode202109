#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
	vector<int> queries = {0, 3, 5};
	Solution *test = new Solution();
	auto result = test->solveQueries(nums, queries);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
