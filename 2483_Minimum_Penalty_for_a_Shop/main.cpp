#include <Solution.h>

int main(void) {
	string input = "NNNYNN";
	Solution *test = new Solution();
	cout << test->bestClosingTime(input) << endl;
	return 0;
}
