#include <Solution.h>

int main(void) {
	string s = "cbacdcbc";
	Solution *test = new Solution();
	cout << test->smallestSubsequence(s) << endl;
	return 0;
}
