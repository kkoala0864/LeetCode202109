#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"cba","daf","ghi"};
	Solution* test = new Solution();
	cout << test->minDeletionSize(input) << endl;
	return 0;
}

