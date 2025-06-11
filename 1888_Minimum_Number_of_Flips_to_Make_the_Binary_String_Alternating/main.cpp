#include <Solution.h>

int main(void) {
	string input = "01001001101";
	Solution *test = new Solution();
	cout << test->minFlips(input) << endl;
	return 0;
}
