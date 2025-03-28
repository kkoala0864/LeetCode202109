#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"hello", "world", "leetcode"};
	vector<string> bannedWords = {"world", "hello"};
	Solution *test = new Solution();
	cout << test->reportSpam(input, bannedWords) << endl;
	return 0;
}
