#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,1,1,4};
	Solution* test = new Solution();
	cout << test->jump(input) << endl;
	cout << test->jump2(input) << endl;
	return 0;
}

