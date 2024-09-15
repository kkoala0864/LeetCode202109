#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "eleetminicoworoep";
	Solution* test = new Solution();
	cout << test->findTheLongestSubstring(input) << endl;
	return 0;
}

