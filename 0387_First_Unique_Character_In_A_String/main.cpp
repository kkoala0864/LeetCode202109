#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "leetcode";
	Solution* test = new Solution();
	cout << test->firstUniqChar(input) << endl;
	return 0;
}

