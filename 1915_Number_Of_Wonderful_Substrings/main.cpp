#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabb";
	Solution* test = new Solution();
	cout << test->wonderfulSubstrings(input) << endl;
	return 0;
}

