#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> left = {4,3};
	vector<int> right = {0,1};
	Solution* test = new Solution();
	cout << test->getLastMoment(4, left, right) << endl;
	return 0;
}

