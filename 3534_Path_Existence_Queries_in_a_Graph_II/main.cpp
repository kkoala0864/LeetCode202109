#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 5;
	vector<int> nums = {1,8,3,4,2};
	int maxDiff = 3;
	vector<vector<int>> queries = {{0,3},{2,4}};
	Solution *test = new Solution();
	auto result = test->pathExistenceQueries(n, nums, maxDiff, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
