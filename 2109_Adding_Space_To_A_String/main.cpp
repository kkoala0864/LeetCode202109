#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "LeetcodeHelpsMeLearn";
	vector<int> spaces = {8,13,15};
	Solution* test = new Solution();
	cout << test->addSpaces(input, spaces) << endl;
	return 0;
}

