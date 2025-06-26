#include <Solution.h>

int main(void) {
	string input = "1001010";
	Solution *test = new Solution();
	cout << test->longestSubsequence(input, 5) << endl;
	return 0;
}
