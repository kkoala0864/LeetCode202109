#include <Solution.h>

int main(void) {
	vector<int> input = {1, 0, 1, 1, 0};
	Solution *test = new Solution();
	cout << test->findMaxConsecutiveOnes(input) << endl;
	return 0;
}
