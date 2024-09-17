#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"23:59","00:00"};
	Solution* test = new Solution();
	cout << test->findMinDifference(input) << endl;
	return 0;
}

