#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,2,3,3,2,4,4,4,4,4};
	Solution* test = new Solution();
	cout << test->minimumRounds(input) << endl;
	return 0;
}

