#include <Solution.h>

int main(void) {
	vector<int> input = {5,-3,5};
	Solution *test = new Solution();
	cout << test->maxSubarraySumCircular(input) << endl;
	return 0;
}
