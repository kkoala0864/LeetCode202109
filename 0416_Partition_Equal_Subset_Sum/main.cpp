#include <Solution.h>

int main(void) {
	vector<int> input = {14,9,8,4,3,2};
	Solution *test = new Solution();
	cout << test->canPartition(input) << endl;
	return 0;
}
