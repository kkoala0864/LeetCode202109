#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string pattern("abba");
	string s("dog cat cat dog");
	Solution *test = new Solution();
	cout << test->wordPattern(pattern, s) << endl;
	cout << test->wordPattern2(pattern, s) << endl;
	return 0;
}
