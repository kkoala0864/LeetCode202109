#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "zjveiiwvc";
	Solution* test = new Solution();
	cout << test->minInsertions(input) << endl;
	return 0;
}

