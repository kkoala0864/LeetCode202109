#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,1,2};
	Solution* test = new Solution();
	cout << test->findMin(input) << endl;
	cout << test->findMin2(input) << endl;
	cout << test->findMin3(input) << endl;
	return 0;
}

