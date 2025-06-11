#include <Solution.h>

int main(void) {
	string input = "abcz";
	int k = 26;
	Solution *test = new Solution();
	cout << test->smallestBeautifulString(input, k) << endl;
	return 0;
}
