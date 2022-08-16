#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"AAAACCCC","AAACCCCC","AACCCCCC"};
	Solution* test = new Solution();
	cout << test->minMutation("AAAAACCC", "AACCCCCC", input) << endl;
	return 0;
}

