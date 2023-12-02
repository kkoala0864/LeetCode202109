#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,0,1,1,0};
	Solution* test = new Solution();
	cout << test->findMaxConsecutiveOnes(input) << endl;
	cout << test->findMaxConsecutiveOnes2(input) << endl;
	return 0;
}

