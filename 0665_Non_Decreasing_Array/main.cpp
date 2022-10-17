#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,2,3};
	Solution* test = new Solution();
	cout << test->checkPossibility(input) << endl;
	cout << test->checkPossibility2(input) << endl;
	return 0;
}

