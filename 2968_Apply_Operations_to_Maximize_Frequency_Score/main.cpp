#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,6,4};
	int k = 3;
	Solution *test = new Solution();
	cout << test->maxFrequencyScore(input, k) << endl;
	return 0;
}
