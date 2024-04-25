#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "eduktdb";
	int k = 15;
	Solution* test = new Solution();
	cout << test->longestIdealString(input, k) << endl;
	return 0;
}

