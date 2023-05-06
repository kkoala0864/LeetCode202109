#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,3,6,8};
	Solution* test = new Solution();
	cout << test->numSubseq(input, 10) << endl;
	return 0;
}

