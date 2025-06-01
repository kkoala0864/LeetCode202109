#include <Solution.h>

int main(void) {
	int n = 5, limit = 2;
	Solution *test = new Solution();
	cout << test->distributeCandies(n, limit) << endl;
	return 0;
}
