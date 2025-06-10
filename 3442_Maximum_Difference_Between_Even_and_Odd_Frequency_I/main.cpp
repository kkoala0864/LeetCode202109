#include <Solution.h>

int main(void) {
	string input = "aaaaabbc";
	Solution *test = new Solution();
	cout << test->maxDifference(input) << endl;
	return 0;
}
