#include <Solution.h>

int main(void) {
	vector<int> nums = {0,0,1,1,0};
	vector<vector<int>> queries = {{3,4},{0,2},{2,3}};
	Solution *test = new Solution();
	cout << test->maxRemoval(nums, queries) << endl;
	return 0;
}

// [0,2], [2,3], [3,4]
// 0 0 1 1 0
