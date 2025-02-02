#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "WS";
	int k = 0;
	Solution* test = new Solution();
	cout << test->maxDistance(input, k) << endl;
	return 0;
}

