#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,5,10};
	Solution* test = new Solution();
	cout << test->getLargestOutlier(input) << endl;
	return 0;
}

