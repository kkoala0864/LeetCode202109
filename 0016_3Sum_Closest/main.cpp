#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-1,2,1,-4};
	Solution* test = new Solution();
	cout << test->threeSumClosest(input, 1) << endl;
	cout << test->threeSumClosest2(input, 1) << endl;
	return 0;
}

