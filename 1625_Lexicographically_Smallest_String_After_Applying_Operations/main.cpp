#include <Solution.h>

int main(void) {
	string s = "5525";
	int a = 9;
	int b = 2;
	Solution *test = new Solution();
	cout << test->findLexSmallestString(s, a, b) << endl;
	return 0;
}
