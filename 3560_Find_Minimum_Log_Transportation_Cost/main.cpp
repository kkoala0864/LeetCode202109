#include <Solution.h>

int main(void) {
	int n = 6, m = 5, k = 5;
	Solution *test = new Solution();
	cout << test->minCuttingCost(n, m, k) << endl;
	return 0;
}
