#include <Solution.h>

int main(void) {
	vector<int> input = {1, 2, 2, 3, 1, 4};
	Solution *test = new Solution();
	cout << test->maxFrequencyElements(input) << endl;
	return 0;
}
