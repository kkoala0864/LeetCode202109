#include <Solution.h>

int main(void) {
	vector<int> input = {1,2,3};
	vector<int> multipliers = {3, 2, 1};
	Solution *test = new Solution();
	cout << test->maximumScore(input, multipliers) << endl;
	return 0;
}
