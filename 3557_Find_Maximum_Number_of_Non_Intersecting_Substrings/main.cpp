#include <Solution.h>

int main(void) {
	string input = "ccaceddad";
	Solution *test = new Solution();
	cout << test->maxSubstrings(input) << endl;
	return 0;
}
