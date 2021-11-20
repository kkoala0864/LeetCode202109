#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,2,3,3,4,4,8,8};
	Solution* test = new Solution();
	cout << test->singleNonDuplicate(input) << endl;
	return 0;
}

