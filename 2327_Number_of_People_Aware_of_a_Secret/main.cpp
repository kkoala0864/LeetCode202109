#include <Solution.h>

int main(void) {
	int n = 6;
	int delay = 2;
	int forget = 4;
	Solution *test = new Solution();
	cout << test->peopleAwareOfSecret(n, delay, forget) << endl;
	return 0;
}
