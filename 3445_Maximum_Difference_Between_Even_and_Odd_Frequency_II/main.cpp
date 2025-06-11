#include <Solution.h>

int main(void) {
	string input = "12233";
	int k = 4;
	Solution *test = new Solution();
	cout << test->maxDifference(input, k) << endl;
	return 0;
}
