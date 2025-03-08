#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "WBBWWBBWBW";
	int k = 7;
	Solution* test = new Solution();
	cout << test->minimumRecolors(input, k) << endl;
	return 0;
}

