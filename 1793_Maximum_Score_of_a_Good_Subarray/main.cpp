#include <Solution.h>

int main(void) {
	vector<int> input = {1,4,3,7,4,5};
	int k = 3;
	Solution *test = new Solution();
	cout << test->maximumScore(input, k) << endl;
	return 0;
}
