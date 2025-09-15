#include <Solution.h>

int main(void) {
	string text = "hello world";
	string brokenLetters = "ad";
	Solution *test = new Solution();
	cout << test->canBeTypedWords(text, brokenLetters) << endl;
	return 0;
}
