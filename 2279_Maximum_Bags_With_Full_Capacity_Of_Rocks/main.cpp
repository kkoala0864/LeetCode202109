#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2, 3, 4, 5};
	vector<int> rocks = {1, 2, 4, 4};
	int additionalRocks = 2;
	Solution *test = new Solution();
	cout << test->maximumBags(input, rocks, additionalRocks) << endl;
	return 0;
}
