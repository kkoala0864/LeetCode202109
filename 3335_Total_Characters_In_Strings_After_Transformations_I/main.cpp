#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abcyy";
	int t = 2;
	Solution* test = new Solution();
	cout << test->lengthAfterTransformations(input, t) << endl;
	return 0;
}

