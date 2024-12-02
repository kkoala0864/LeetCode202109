#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "this problem is an easy problem";
	string pre = "pro";
	Solution* test = new Solution();
	cout << test->isPrefixOfWord(input, pre) << endl;
	return 0;
}

