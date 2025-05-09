#include <Solution.h>

int main(void) {
	string input = "22431051238906437161377495483547";
	Solution *test = new Solution();
	cout << test->countBalancedPermutations(input) << endl;
	return 0;
}
