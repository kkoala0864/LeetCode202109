#include <Solution.h>

int main(void) {
	vector<int> input = {1,7,9,8,2};
	int k = 2;
	Solution *test = new Solution();
	cout << test->maximumProfit(input, k) << endl;
	return 0;
}
