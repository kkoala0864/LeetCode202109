#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("ababbc");
	Solution* test = new Solution();
	cout << test->longestSubstring(input, 2) << endl;
	return 0;
}

