#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, -3};
	Solution *test = new Solution();
	cout << test->containsNearbyAlmostDuplicate(input, 2, 4) << endl;
	cout << test->containsNearbyAlmostDuplicate2(input, 2, 4) << endl;
	cout << test->containsNearbyAlmostDuplicate3(input, 2, 4) << endl;
	return 0;
}
