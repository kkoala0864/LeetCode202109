#include <Solution.h>

int main(void) {
	vector<int> input = {1, 2, 5};
	Solution *test = new Solution();
	cout << test->coinChange(input, 11) << endl;
	return 0;
}
