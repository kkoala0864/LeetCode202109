#include <Solution.h>

int main(void) {
	string input = "cdbcbbaaabab";
	Solution *test = new Solution();
	cout << test->maximumGain(input, 4, 5) << endl;
	return 0;
}
