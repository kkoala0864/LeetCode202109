#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"a","abb"};
	Solution* test = new Solution();
	cout << test->countPrefixSuffixPairs(input) << endl;
	return 0;
}

