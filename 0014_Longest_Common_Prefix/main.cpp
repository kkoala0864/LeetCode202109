#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"flower", "flow", "flight"};
	Solution *test = new Solution();
	cout << test->longestCommonPrefix(input) << endl;
	cout << test->longestCommonPrefix2(input) << endl;
	return 0;
}
