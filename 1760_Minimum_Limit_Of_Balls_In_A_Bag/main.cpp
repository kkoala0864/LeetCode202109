#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,4,8,2};
	int n = 4;
	Solution* test = new Solution();
	cout << test->minimumSize(input, n) << endl;
	return 0;
}

