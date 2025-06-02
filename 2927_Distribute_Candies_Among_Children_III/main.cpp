#include <Solution.h>

int main(void) {
	int n = 3;
	int limit = 3;
	Solution *test = new Solution();
	cout << test->distributeCandies(n, limit) << endl;
	return 0;
}
