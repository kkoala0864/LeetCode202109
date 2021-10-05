#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"z", "z"};
	Solution* test = new Solution();
	cout << test->alienOrder(input) << endl;
	return 0;
}

