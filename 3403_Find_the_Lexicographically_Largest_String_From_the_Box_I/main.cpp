#include <Solution.h>

int main(void) {
	string input = "gggg";
	int num = 4;
	Solution *test = new Solution();
	cout << test->answerString(input, num) << endl;
	return 0;
}
