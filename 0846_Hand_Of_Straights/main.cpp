#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 6, 2, 3, 4, 7, 8};
	int groupSize = 3;
	Solution *test = new Solution();
	cout << test->isNStraightHand(input, groupSize) << endl;
	return 0;
}
