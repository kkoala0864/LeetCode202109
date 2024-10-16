#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int a = 1, b = 1, c = 7;
	Solution* test = new Solution();
	cout << test->longestDiverseString(a, b, c) << endl;
	return 0;
}

