#include <Solution.h>

int main(void) {
	int n = 10, x = 2;
	Solution *test = new Solution();
	cout << test->numberOfWays(n, x) << endl;
	return 0;
}
