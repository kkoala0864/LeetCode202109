#include <Solution.h>

int main(void) {
	vector<int> input = {2,6,3,4,3};
	Solution *test = new Solution();
	cout << test->validSubarraySplit(input) << endl;
	return 0;
}
