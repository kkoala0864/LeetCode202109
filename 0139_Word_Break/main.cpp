#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	Solution* test = new Solution();
	cout << test->wordBreak(input, wordDict) << endl;
	cout << test->wordBreak2(input, wordDict) << endl;
	return 0;
}

