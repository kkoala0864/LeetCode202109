#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,4,2,2};
	Solution* test = new Solution();
	cout << test->findDuplicate(input) << endl;
	cout << test->findDuplicate2(input) << endl;
	return 0;
}

