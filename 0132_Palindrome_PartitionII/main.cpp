#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("aab");
	Solution* test = new Solution();
	cout << test->minCut(input) << endl;
	return 0;
}

