#include <Solution.h>

int main(void) {
	int n = 9;
	vector<int> input = {5, 6, 1, 4, 2};
	Solution *test = new Solution();
	cout << test->minCost(n, input) << endl;
	return 0;
}
