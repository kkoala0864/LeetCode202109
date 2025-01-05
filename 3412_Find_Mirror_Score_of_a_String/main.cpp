#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aczzx";
	Solution* test = new Solution();
	cout << test->calculateScore(input) << endl;
	return 0;
}

