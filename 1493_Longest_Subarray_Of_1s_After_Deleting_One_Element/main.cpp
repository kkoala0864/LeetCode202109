#include <Solution.h>

int main(void) {
	vector<int> input = {0, 1, 1, 1, 0, 1, 1, 0, 1};
	Solution *test = new Solution();
	cout << test->longestSubarray(input) << endl;
	return 0;
}
