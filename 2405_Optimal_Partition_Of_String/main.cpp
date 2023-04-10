#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abacaba";
	Solution* test = new Solution();
	cout << test->partitionString(input) << endl;
	return 0;
}

