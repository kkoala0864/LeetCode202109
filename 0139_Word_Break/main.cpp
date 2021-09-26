#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "catsandog";
	vector<string> wordDict = {"cats","dog","sand","and","cat"};
	Solution* test = new Solution();
	cout << test->wordBreak(input, wordDict) << endl;
	return 0;
}

