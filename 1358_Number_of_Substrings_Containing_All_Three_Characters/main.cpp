#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aaacb";
	Solution *test = new Solution();
	cout << test->numberOfSubstrings(input) << endl;
	return 0;
}
