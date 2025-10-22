#include <Solution.h>

int main(void) {
	vector<int> input = {5, 64};
	int k = 42;
	int numOperations = 2;
	Solution *test = new Solution();
	cout << test->maxFrequency(input, k, numOperations) << endl;
	return 0;
}
