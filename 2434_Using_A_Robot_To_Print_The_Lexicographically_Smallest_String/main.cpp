#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "mmuqezwmomeplrtskz";
	Solution* test = new Solution();
	cout << test->robotWithString(input) << endl;
	return 0;
}

