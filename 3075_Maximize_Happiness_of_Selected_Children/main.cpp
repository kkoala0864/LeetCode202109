#include <Solution.h>

int main(void) {
	vector<int> input = {2, 3, 4, 5};
	int k = 1;
	Solution *test = new Solution();
	cout << test->maximumHappinessSum(input, k) << endl;
	return 0;
}
