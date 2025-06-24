#include <Solution.h>

int main(void) {
	vector<int> input = {1};
	int k = 1;
	Solution *test = new Solution();
	cout << test->shortestSubarray(input, k) << endl;
	return 0;
}
