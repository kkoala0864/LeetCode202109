#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string v1 = "1.0.1";
	string v2 = "1";
	Solution* test = new Solution();
	cout << test->compareVersion(v1, v2) << endl;
	return 0;
}

