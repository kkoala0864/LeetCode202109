#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 1, 2, 3};
	Solution *test = new Solution();
	cout << test->containsNearbyDuplicate(input, 2) << endl;
	cout << test->containsNearbyDuplicate2(input, 2) << endl;
	return 0;
}
