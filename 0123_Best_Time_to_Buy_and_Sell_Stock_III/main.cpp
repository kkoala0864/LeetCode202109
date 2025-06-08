#include <Solution.h>

int main(void) {
	vector<int> input = {3, 3, 5, 0, 0, 3, 1, 4};
	Solution *test = new Solution();
	cout << test->maxProfit(input) << endl;
	return 0;
}
