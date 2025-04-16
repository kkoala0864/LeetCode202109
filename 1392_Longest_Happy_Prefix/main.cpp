#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "level";
	Solution *test = new Solution();
	cout << test->longestPrefix(input) << endl;
	return 0;
}
