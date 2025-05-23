#include <Solution.h>

int main(void) {
	vector<int> nums = {24,78,1,97,44};
	int k = 6;
	vector<vector<int>> edges = {{0,2},{1,2},{4,2},{3,4}};
	Solution *test = new Solution();
	cout << test->maximumValueSum(nums, k, edges) << endl;
	return 0;
}
