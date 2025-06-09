#include <Solution.h>

int main(void) {
	int n = 10;
	int k = 3;
	Solution *test = new Solution();
	cout << test->findKthNumber(n, k) << endl;
	return 0;
}
