#include <Solution.h>

int main(void) {
	int lo = 12;
	int hi = 15;
	int k = 2;
	Solution *test = new Solution();
	cout << test->getKth(lo, hi, k) << endl;
	return 0;
}
