#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> h = {1,2,4};
	vector<int> w = {1,3};
	Solution* test = new Solution();
	cout << test->maxArea(5,4,h,w) << endl;
	return 0;
}

