#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "110110100100";
	Solution* test = new Solution();
	cout << test->makeLargestSpecial(input) << endl;
	return 0;
}

