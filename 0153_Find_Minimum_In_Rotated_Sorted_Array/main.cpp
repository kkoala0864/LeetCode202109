#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,1};
	Solution* test = new Solution();
	cout << test->findMin(input) << endl;
	cout << test->findMin2(input) << endl;
	return 0;
}

