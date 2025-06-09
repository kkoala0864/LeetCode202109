#include <Solution.h>

int main(void) {
	vector<int> coins = {1, 2, 5};
	Solution *test = new Solution();
	cout << test->change(5, coins) << endl;
	return 0;
}
