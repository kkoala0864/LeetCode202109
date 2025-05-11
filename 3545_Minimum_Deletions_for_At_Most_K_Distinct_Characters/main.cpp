#include <Solution.h>

int main(void) {
	string s = "abc";
	int k = 2;
	Solution *test = new Solution();
	cout << test->minDeletion(s, k) << endl;
	return 0;
}
