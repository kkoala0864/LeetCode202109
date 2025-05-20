#include <Solution.h>

int main(void) {
	string input = "acab";
	Solution *test = new Solution();
	cout << test->checkPartitioning(input) << endl;
	return 0;
}
