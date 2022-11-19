#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "horse";
	string s2 = "ros";
	Solution* test = new Solution();
	cout << test->minDistance(s1, s2) << endl;
	cout << test->minDistance2(s1, s2) << endl;
	return 0;
}

