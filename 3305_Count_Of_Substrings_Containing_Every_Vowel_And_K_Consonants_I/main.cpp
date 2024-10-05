#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "iqeaouqi";
	int k = 2;
	Solution* test = new Solution();
	cout << test->countOfSubstrings(input, k) << endl;
	return 0;
}

