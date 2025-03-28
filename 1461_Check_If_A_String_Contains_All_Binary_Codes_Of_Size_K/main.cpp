#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "0110";
	Solution *test = new Solution();
	cout << test->hasAllCodes(input, 2) << endl;
	return 0;
}
