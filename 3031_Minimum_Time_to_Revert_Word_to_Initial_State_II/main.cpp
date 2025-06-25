#include <Solution.h>

int main(void) {
	string s = "abaabab";
	int k = 3;
	Solution *test = new Solution();
	cout << test->minimumTimeToInitialState(s, k) << endl;
	return 0;
}
