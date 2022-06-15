#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"a","b","ba","bca","bda","bdca"};
	Solution* test = new Solution();
	cout << test->longestStrChain(input) << endl;
	return 0;
}

