#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "xyz";
	string input2 = "xzyxz";
	Solution* test = new Solution();
	cout << test->shortestWay(input1, input2) << endl;
	return 0;
}

