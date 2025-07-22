#include <Solution.h>

int main(void) {
	vector<int> input = {5, 2, 1, 2, 5, 2, 1, 2, 5};
	Solution *test = new Solution();
	cout << test->maximumUniqueSubarray(input) << endl;
	return 0;
}
