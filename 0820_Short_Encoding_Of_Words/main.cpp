#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"time", "me", "bell"};
	Solution* test = new Solution();
	cout << test->minimumLengthEncoding(input) << endl;
	return 0;
}

