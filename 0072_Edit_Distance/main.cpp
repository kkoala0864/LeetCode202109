#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "intention";
	string s2 = "execution";
	Solution* test = new Solution();
	cout << test->minDistance(s1, s2) << endl;
	return 0;
}

