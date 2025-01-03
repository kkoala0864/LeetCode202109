#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,4,3,4,3,4,3,4};
	Solution* test = new Solution();
	cout << test->numberOfSubsequences(input) << endl;
	return 0;
}

