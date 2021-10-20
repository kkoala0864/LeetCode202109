#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,5,9,1,5,9};
	Solution* test = new Solution();
	cout << test->containsNearbyAlmostDuplicate(input, 2, 3) << endl;
	return 0;
}

