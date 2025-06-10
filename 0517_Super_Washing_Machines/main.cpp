#include <Solution.h>

int main(void) {
	vector<int> nums = {0, 0, 11, 5};
	Solution *test = new Solution();
	cout << test->findMinMoves(nums) << endl;
	return 0;
}
