#include <Solution.h>

int main(void) {
	string s = "aabbccdd";
	int k = 7;
	Solution *test = new Solution();
	cout << test->possibleStringCount(s, k) << endl;
	return 0;
}
