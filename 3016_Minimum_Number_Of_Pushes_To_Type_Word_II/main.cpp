#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabbccddeeffgghhiiiiii";
	Solution* test = new Solution();
	cout << test->minimumPushes(input) << endl;
	return 0;
}

