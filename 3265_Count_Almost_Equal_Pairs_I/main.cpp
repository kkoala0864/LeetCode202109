#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,12,30,17,21};
	Solution* test = new Solution();
	cout << test->countPairs(input) << endl;
	return 0;
}

