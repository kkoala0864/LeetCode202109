#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "Let's take LeetCode contest";
	Solution* test = new Solution();
	cout << test->reverseWords(input) << endl;
	return 0;
}

