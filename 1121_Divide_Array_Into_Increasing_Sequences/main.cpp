#include <Solution.h>

int main(void) {
	vector<int> input = {5,6,6,7,8};
	int k = 3;
	Solution *test = new Solution();
	cout << test->canDivideIntoSubsequences(input, k) << endl;
	return 0;
}
