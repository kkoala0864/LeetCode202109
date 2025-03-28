#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "ieaouqqieaouqq";
	int k = 1;
	Solution *test = new Solution();
	cout << test->countOfSubstrings(input, k) << endl;
	return 0;
}
