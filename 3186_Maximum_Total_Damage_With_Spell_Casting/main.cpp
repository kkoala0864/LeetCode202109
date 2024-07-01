#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {5,9,2,10,2,7,10,9,3,8};
	Solution* test = new Solution();
	cout << test->maximumTotalDamage(input) << endl;
	return 0;
}

