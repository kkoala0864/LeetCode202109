#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{1,4},{2,3}};
	Solution *test = new Solution();
	cout << test->canPartitionGrid(input) << endl;
	return 0;
}
