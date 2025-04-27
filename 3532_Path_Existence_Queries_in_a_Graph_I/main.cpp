#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {1, 3};
	vector<vector<int>> queries = {{0,0},{0,1}};
	int n = 2;
	int maxDiff = 1;
	Solution *test = new Solution();
	auto result = test->pathExistenceQueries(n, nums, maxDiff, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
