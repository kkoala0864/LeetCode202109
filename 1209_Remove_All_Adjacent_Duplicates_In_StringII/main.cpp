#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abcd";
	Solution* test = new Solution();
	cout << test->removeDuplicates(input, 2) << endl;
	return 0;
}

