#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "rabbbit";
	string s2 = "rabbit";
	Solution* test = new Solution();
	cout << test->numDistinct(s1, s2) << endl;
	return 0;
}

